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

ll MOD = 1e9;
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
    vector<vl> res(c.size() + 1);
    res[0].pb(1);
    FORrev(i, c.size() - 1)
    {
        res[0].pb(c[i]);
    }
    FORe(i, c.size())
    {
        res[i].pb(0);
    }
    FORe(i, c.size() - 1)
    {
        res[i].pb(0);
    }
    for (int i = 1; i < c.size(); i++)
    {
        for (int j = 2; j < c.size() + 1; j++)
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
        res[c.size()].pb(c[i]);
    }
    return res;
}
vector<vl> multiply(vector<vl> &a, vector<vl> &b)
{
    vector<vl> res(a.size());
    FOR(i, a.size())
    {
        res[i].resize(b[0].size());
        FOR(j, b[0].size())
        {
            res[i][j] = 0;
            FOR(k, a[0].size())
            {
                res[i][j] += (((a[i][k] % MOD) * (b[k][j] % MOD)) % MOD);
            }
        }
    }
    return res;
}
vector<vl> power(vector<vl> &A, ll n)
{
    if (n == 1)
    {
        return A;
    }
    vector<vl> res = power(A, n / 2);
    res = multiply(res, res);
    if (n & 1)
    {
        res = multiply(res, A);
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
    ll m, n;
    cin >> m >> n >> MOD;
    ll ans1 = 0;
    ll ans2 = 0;
    ll sum = accumulate(all(b), 0LL) % MOD;
    if (n <= k)
    {
        ans1 = accumulate(b.begin(), b.begin() + n, 0LL) % MOD;
    }
    if (m - 1 <= k)
    {
        ans2 = accumulate(c.begin(), c.begin() + m - 1, 0LL) % MOD;
    }
    b.insert(b.begin(), sum);
    vector<vl> t_mat = generateTmatrix(c);
    if (n > k)
    {
        vector<vl> mod_t_mat1 = power(t_mat, n - k);
        FOR(i, k + 1)
        {
            ans1 += (((mod_t_mat1[0][i] % MOD) * (b[i] % MOD)) % MOD);
        }
    }
    if (m - 1 > k)
    {
        vector<vl> mod_t_mat2 = power(t_mat, m - k - 1);
        FOR(i, k + 1)
        {
            ans2 += (((mod_t_mat2[0][i] % MOD) * (b[i] % MOD)) % MOD);
        }
    }
    cout << (((ans1 - ans2) % MOD) + MOD) % MOD;
}