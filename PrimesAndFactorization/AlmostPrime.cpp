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

ll fastExponentiation1(ll a, ll b)
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

ll fastExponentiation2(ll a, ll b)
{
    if (b == 0)
    {
        return 1;
    }
    ll res = fastExponentiation2(a, b / 2);
    res *= res;
    if (b & 1)
    {
        res *= a;
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

vl factorial;
void factorial_init(ll n)
{
    factorial.clear();
    factorial.resize(n + 1);
    factorial[0] = 1;
    FOR(i, n)
    {
        factorial[i + 1] = factorial[i] * (i + 1);
    }
}

map<ll, ll> fib;
ll fibonacci_helper(ll n)
{
    if (fib.count(n))
    {
        return fib[n];
    }
    if (n & 1)
    {
        return fib[n] = fibonacci_helper(n / 2) * fibonacci_helper(n / 2 + 1) + fibonacci_helper(n / 2) * fibonacci_helper(n / 2 - 1);
    }
    else
    {
        return fib[n] = fibonacci_helper(n / 2) * fibonacci_helper(n / 2) + fibonacci_helper(n / 2 - 1) * fibonacci_helper(n / 2 - 1);
    }
}
ll fibonacci(ll n)
{
    if (n == 0)
    {
        return 0;
    }
    if (!fib.count(0))
    {
        fib[0] = fib[1] = 1;
    }
    return fibonacci_helper(n - 1);
}

vector<vl> pascalTriangle;
void ncr_init(ll n)
{
    pascalTriangle.clear();
    pascalTriangle.resize(n + 1);
    FOR(i, n + 1)
    {
        pascalTriangle[i].resize(i + 1);
        pascalTriangle[i][0] = 1;
        pascalTriangle[i][i] = 1;
        FORe(j, i - 1)
        {
            pascalTriangle[i][j] = pascalTriangle[i - 1][j - 1] + pascalTriangle[i - 1][j];
        }
    }
}

vector<vl> generateTransformationMatrix(vl &c)
{
    vector<vl> res(c.size());
    FOR(i, c.size() - 1)
    {
        res[i].pb(0);
    }
    FOR(i, c.size() - 1)
    {
        FORe(j, c.size() - 1)
        {
            if (i + 1 == j)
            {
                res[i].pb(1);
            }
            else
            {
                res[i].pb(0);
            }
        }
    }
    FORrev(i, c.size() - 1)
    {
        res[c.size() - 1].pb(c[i]);
    }
    return res;
}

vector<vl> matrixMultiply(vector<vl> &a, vector<vl> &b)
{
    vector<vl> res(a.size());
    FOR(i, a.size())
    {
        res[i].resize(b[0].size());
    }
    FOR(i, a.size())
    {
        FOR(j, b[0].size())
        {
            FOR(k, a[0].size())
            {
                res[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return res;
}

vector<vl> matrixPower(vector<vl> &a, ll n)
{
    if (n == 0)
    {
        vector<vl> res(a.size());
        FOR(i, a.size())
        {
            res[i].resize(a[0].size());
            FOR(j, a[0].size())
            {
                if (i == j)
                {
                    res[i][j] = 1;
                }
                else
                {
                    res[i][j] = 0;
                }
            }
        }
        return res;
    }
    vector<vl> res = matrixPower(a, n / 2);
    res = matrixMultiply(res, res);
    if (n & 1)
    {
        res = matrixMultiply(res, a);
    }
    return res;
}

vector<int> prime;
void sieve_init(ll n)
{
    prime.clear();
    prime.resize(n + 1);
    prime[1]=1;
    for (ll i = 2; i <= n; i++)
    {
        if (!prime[i])
        {
            for(int j=i*2;j<=n;j+=i)
            {
                prime[j]++;
            }
        }
    }
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
    
    return 0;
}

/*Your functions here*/

void solve()
{
    int n;
    cin>>n;
    ll ans=0;
    sieve_init(n);
    for(int i=1;i<=n;i++){
        if(prime[i]==2){
            ans++;
        }
    }
    cout<<ans;
}