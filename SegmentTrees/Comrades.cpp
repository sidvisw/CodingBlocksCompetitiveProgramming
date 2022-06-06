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
const ll MAXN = 1e5 + 5;
/*----------------------------------------------------------------------*/

void solve();

/*------------------------SOME IMPORTANT FUNCTIONS----------------------*/

/*----------------------------------------------------------------------*/

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
vi graph[MAXN];
int lazy[4 * MAXN + 1];
int in[MAXN], out[MAXN];
bool visited[MAXN];
vi stk;
// int tme = -1;
void dfs(int head)
{
    visited[head] = true;
    // tme++;
	stk.pb(head);
    in[head] = stk.size()-1;
    for (auto it : graph[head])
    {
        if (!visited[it])
        {
            dfs(it);
        }
    }
    out[head] = stk.size()-1;
}
void buildTree(vl &tree, int s, int e, int index)
{
    if (s == e)
    {
        tree[index] = 1;
        return;
    }
    int mid = (s + e) / 2;
    buildTree(tree, s, mid, 2 * index);
    buildTree(tree, mid + 1, e, 2 * index + 1);
    tree[index] = tree[2 * index] + tree[2 * index + 1];
}
void updateTree(vl &tree, int s, int e, int l, int r, int val, int index)
{
    if (lazy[index] != 0)
    {
        if (lazy[index] == 1)
        {
            tree[index] = e - s + 1;
        }
        else
        {
            tree[index] = 0;
        }
        if (s != e)
        {
            lazy[2 * index] = lazy[index];
            lazy[2 * index + 1] = lazy[index];
        }
        lazy[index] = 0;
    }
    if (s > e || l > e || r < s)
    {
        return;
    }
    if (l <= s && e <= r)
    {
        if (val == 1)
        {
            tree[index] = e - s + 1;
        }
        else
        {
            tree[index] = 0;
        }
        if (s != e)
        {
            lazy[2 * index] = val;
            lazy[2 * index + 1] = val;
        }
        return;
    }
    int mid = (s + e) / 2;
    updateTree(tree, s, mid, l, r, val, 2 * index);
    updateTree(tree, mid + 1, e, l, r, val, 2 * index + 1);
    tree[index] = tree[2 * index] + tree[2 * index + 1];
}
int query(vl &tree, int s, int e, int l, int r, int index)
{
    if (lazy[index] != 0)
    {
        if (lazy[index] == 1)
        {
            tree[index] = e - s + 1;
        }
        else
        {
            tree[index] = 0;
        }
        if (s != e)
        {
            lazy[2 * index] = lazy[index];
            lazy[2 * index + 1] = lazy[index];
        }
        lazy[index] = 0;
    }
    if (s > e || l > e || r < s)
    {
        return 0;
    }
    if (l <= s && e <= r)
    {
        return tree[index];
    }
    int mid = (s + e) / 2;
    return query(tree, s, mid, l, r, 2 * index) + query(tree, mid + 1, e, l, r, 2 * index + 1);
}
void solve()
{
    int n;
    cin >> n;
    int head;
    FOR(i, n)
    {
        int node;
        cin >> node;
        if (node == 0)
        {
            head = i + 1;
            continue;
        }
        graph[node].pb(i + 1);
    }
    dfs(head);
    vl tree(4 * n + 1);
    buildTree(tree, 0, n - 1, 1);
    int q;
    cin >> q;
    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int s;
            cin >> s;
            updateTree(tree, 0, n - 1, in[s] + 1, out[s], 1, 1);
        }
        else if (type == 2)
        {
            int s;
            cin >> s;
            updateTree(tree, 0, n - 1, in[s] + 1, out[s], -1, 1);
        }
        else
        {
            int s;
            cin >> s;
            cout << query(tree, 0, n - 1, in[s] + 1, out[s], 1) << endl;
        }
    }
}