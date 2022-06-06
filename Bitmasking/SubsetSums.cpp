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

const ll MOD = 1e9 + 7;
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
    // /*Is Single Test Case?*/ cin >> t;
    while (t--)
    {
        solve();
        cout << endl;
    }
    
    cerr << "Time Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
    return 0;
}

/*Your functions here*/

void solve()
{
    ll n,a,b;
    cin>>n>>a>>b;
    vl v(n);
    FOR(i,n)cin>>v[i];
    vl s1,s2;
    FOR(i,n/2){
        s1.pb(v[i]);
    }
    FORr(i,n/2,n){
        s2.pb(v[i]);
    }
    vector<vl> subset1=generateSubsets(s1);
    vector<vl> subset2=generateSubsets(s2);
    vl subset1sum,subset2sum;
    FOR(i,subset1.size()){
        subset1sum.pb(0);
        FOR(j,subset1[i].size()){
            subset1sum[i]+=subset1[i][j];
        }
    }
    FOR(i,subset2.size()){
        subset2sum.pb(0);
        FOR(j,subset2[i].size()){
            subset2sum[i]+=subset2[i][j];
        }
    }
    sort(all(subset1sum));
    sort(all(subset2sum));
    ll ans=0;
    for(auto x:subset1sum){
        int y1=a-x;
        int y2=b-x;
        int idx1=lower_bound(all(subset2sum),y1)-subset2sum.begin();
        int idx2=upper_bound(all(subset2sum),y2)-subset2sum.begin();
        ans+=idx2-idx1;
    }
    cout<<ans;
}