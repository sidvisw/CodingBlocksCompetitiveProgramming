#include <bits/stdc++.h>

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
/*----------------------------------------------------------------------*/

using namespace std;

/*------------------------IMPORTANT CONSTANTS---------------------------*/
const int Alp = 26;
const int __PRECISION = 9;
const int inf = 1e9 + 8;

const ldd PI = acos(-1);
const ldd EPS = 1e-7;

const ll MOD = 1e9;
const ll MAXN = 2e5 + 5;
const ll ROOTN = 320;
const ll LOGN = 18;
const ll INF = 1e18 + 1022;
/*----------------------------------------------------------------------*/

void solve();

/*------------------------SOME IMPORTANT FUNCTIONS----------------------*/
vi decimalToBinary(ll n)
{
    vi res;
    while (n > 0)
    {
        res.pb(n & 1);
        n >>= 1;
    }
    return res;
}

ll binaryToDecimal(vi &v)
{
    ll res = 0;
    FOR(i, v.size())
    {
        res += v[i] * (1ll << i);
    }
    return res;
}

ll fastExponentiation(ll a, ll b)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            res *= a;
        }
        b >>= 1;
        a *= a;
    }
    return res;
}

vector<vl> generateSubsets(vl v)
{
    vector<vl> res;
    ll numSubsets = 1 << v.size();
    FOR(i, numSubsets)
    {
        vl temp;
        FOR(j, v.size())
        {
            if (i & (1 << j))
            {
                temp.pb(v[j]);
            }
        }
        res.pb(temp);
    }
    return res;
}
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
    /*Is Single Test Case?*/ cin >> t;
    while (t--)
    {
        solve();
        cout << endl;
    }
    
    cerr << "Time Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
    return 0;
}

/*Your functions here*/
vector<vl> generateTmatrix(vl &c)
{
    vector<vl> res(c.size());
    FOR(i,c.size()-1){
        res[i].pb(0);
    }
    for(int i=0;i<c.size()-1;i++){
        for(int j=0;j<c.size()-1;j++){
            if(i==j){
                res[i].pb(1);
            }
            else{
                res[i].pb(0);
            }
        }
    }
    FORrev(i,c.size()-1){
        res[c.size()-1].pb(c[i]);
    }
    return res;
}
vector<vl> multiply(vector<vl> &a,vector<vl> &b){
    vector<vl> res(a.size());
    FOR(i,a.size()){
        res[i].resize(b[0].size());
        FOR(j,b[0].size()){
            res[i][j]=0;
            FOR(k,a[0].size()){
                res[i][j]+=(((a[i][k]%MOD)*(b[k][j]%MOD))%MOD);
            }
        }
    }
    return res;
}
vector<vl> power(vector<vl> &A,ll n){
    if(n==1){
        return A;
    }
    vector<vl> res=power(A,n/2);
    res=multiply(res,res);
    if(n&1){
        res=multiply(res,A);
    }
    return res;
}
void solve()
{
    ll k;
    cin >> k;
    vl b(k);
    FOR(i, k)
    {
        cin >> b[i];
    }
    vl c(k);
    FOR(i, k)
    {
        cin >> c[i];
    }
    ll n;
    cin >> n;
    if(n<=k){
        cout<<b[n-1];
        return;
    }
    vector<vl> t_mat=generateTmatrix(c);
    vector<vl> mod_t_mat=power(t_mat,n-k);
    ll ans=0;
    FOR(i,k){
        ans+=(((mod_t_mat[k-1][i]%MOD)*(b[i]%MOD))%MOD);
    }
    cout<<ans%MOD;
}