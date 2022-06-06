#include <bits/stdc++.h>
using namespace std;

/*-------------------------IMPORTANT #DEFINES---------------------------*/
#define endl '\n'
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ff first
#define ss second
#define vi vector<int>
#define vl vector<ll>
#define vii vector<pii>
#define vll vector<pll>
#define FOR(i, N) for (int i = 0; i < (N); ++i)
#define FORe(i, N) for (int i = 1; i <= (N); ++i)
#define FORr(i, a, b) for (ll i = (a); i < (b); ++i)
#define FORrev(i, N) for (int i = (N); i >= 0; --i)
#define F0R(i, N) for (i = 0; i < (N); ++i)
#define F0Re(i, N) for (i = 1; i <= (N); ++i)
#define F0Rr(i, a, b) for (i = (a); i < (b); ++i)
#define F0Rrev(i, N) for (i = (N); i >= 0; --i)
#define all(v) (v).begin(), (v).end()
#define dbgLine cerr << " LINE : " << __LINE__ << '\n'
#define ldd long double
/*Is the input/output taken from/to files?*/ #define ONLINE_JUDGE 0

/*---------------------POLICY BASED DATA STRUCTURE----------------------*/

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

/*------------------------IMPORTANT CONSTANTS---------------------------*/
const int Alp = 26;
const int __PRECISION = 9;
const int inf = 1e9 + 8;

const ldd PI = acos(-1);
const ldd EPS = 1e-7;

const ll MOD = 1e9 + 7;
const ll MAXN = 2e5+5;
const ll ROOTN = 320;
const ll LOGN = 18;
const ll INF = 1e18 + 1022;
/*----------------------------------------------------------------------*/

void solve();

/*------------------------SOME IMPORTANT FUNCTIONS----------------------*/

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("error.txt", "w", stderr);
    freopen("output.txt", "w", stdout);
#endif
    
    int t = 1;
    // /*Is Single Test Case?*/ cin >> t;
    while (t--)
    {
        solve();
        // cout << endl;
    }
    
    return 0;
}

/*Your functions here*/
struct node{
    int val;
    node *left, *right;
};
node* newNode(int val, node *left=NULL, node *right=NULL){
    node *temp = new node;
    temp->val = val;
    temp->left = left;
    temp->right = right;
    return temp;
}
int a[MAXN],maxi=0;
vector<int> graph[MAXN];
map<int,int> M;
int RM[MAXN];
node* rootArray[MAXN];
vi euler;
int first[MAXN];
vi height;
vi segTree;
node*none=newNode(0);
bool visited[MAXN]={0};
int parent[MAXN];
node* createTree(int v,int s,int e,node*parent){
    int wt=a[v];
    int mappedValue=M[wt];
    if(mappedValue<s||mappedValue>e){
        return parent;
    }
    if(s==e){
        node*temp=newNode(parent->val+1,none,none);
        return temp;
    }
    int mid=(s+e)/2;
    node*left=createTree(v,s,mid,parent->left);
    node*right=createTree(v,mid+1,e,parent->right);
    node*temp=newNode(parent->val+1,left,right);
    return temp;
}
void dfs(int v,int ht,int p){
    visited[v]=1;
    parent[v]=p;
    rootArray[v]=createTree(v,0,maxi-1,(p==-1)?none:rootArray[p]);
    euler.pb(v);
    first[v]=euler.size()-1;
    height.pb(ht);
    for(int i=0;i<graph[v].size();i++){
        int u=graph[v][i];
        if(!visited[u]){
            dfs(u,ht+1,v);
            euler.pb(v);
            height.pb(ht);
        }
    }
}
void buildSegTree(vi&segTree,int s,int e,int index){
    if(s==e){
        segTree[index]=s;
        return;
    }
    int mid=(s+e)/2;
    buildSegTree(segTree,s,mid,2*index);
    buildSegTree(segTree,mid+1,e,2*index+1);
    if(height[segTree[2*index]]>height[segTree[2*index+1]]){
        segTree[index]=segTree[2*index+1];
    }
    else{
        segTree[index]=segTree[2*index];
    }
}
int query(vi&segtree,int s,int e,int l,int r,int index){
    if(r<s||l>e)return -1;
    if(s>=l&&e<=r){
        return segtree[index];
    }
    int mid=(s+e)/2;
    int left=query(segtree,s,mid,l,r,2*index);
    int right=query(segtree,mid+1,e,l,r,2*index+1);
    if(left==-1)return right;
    if(right==-1)return left;
    if(height[left]>height[right])return right;
    return left;
}
int lca(int u,int v){
    if(first[u]>first[v])swap(u,v);
    return euler[query(segTree,0,euler.size()-1,first[u],first[v],1)];
}
int queryK(node*u,node*v,node*LCA,node*parentLCA,int s,int e,int k,int sum){
    int curr=u->val+v->val-LCA->val-parentLCA->val;
    int left=u->left->val+v->left->val-LCA->left->val-parentLCA->left->val;
    int right=u->right->val+v->right->val-LCA->right->val-parentLCA->right->val;
    int mid=(s+e)/2;
    if(s==e){
        return RM[s];
    }
    if(k<=sum+left){
        return queryK(u->left,v->left,LCA->left,parentLCA->left,s,mid,k,sum);
    }
    else{
        return queryK(u->right,v->right,LCA->right,parentLCA->right,mid+1,e,k,sum+left);
    }
}
void solve()
{
    int n,m;
    cin>>n>>m;
    FORe(i,n)
    {
        cin>>a[i];
        M[a[i]];
    }
    for(auto &p:M){
        M[p.ff]=maxi;
        RM[maxi]=p.ff;
        maxi++;
    }
    none->left=none->right=none;
    FORe(i,n-1){
        graph[i].pb(i+1);
        graph[i+1].pb(i);
    }
    dfs(1,0,-1);
    segTree.clear();
    segTree.resize(4*euler.size()+1);
    buildSegTree(segTree,0,euler.size()-1,1);
    FOR(i,m){
        int u,v,k;
        cin>>u>>v>>k;
        cout<<queryK(rootArray[u],rootArray[v],rootArray[lca(u,v)],((parent[lca(u,v)]==-1)?none:rootArray[parent[lca(u,v)]]),0,maxi-1,k,0)<<endl;
    }
}