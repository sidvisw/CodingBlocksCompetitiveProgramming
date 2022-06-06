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
    if (b == 0)
    {
        return 1;
    }
    ll res = fastExponentiation(a, b / 2);
    res *= res;
    if (b & 1)
    {
        res *= a;
    }
    return res;
}

vector<vl> generateSubsets(vl v)
{
    if (v.size() == 0)
    {
        vector<vl> res;
        res.pb({});
        return res;
    }
    ll last = v.back();
    v.pop_back();
    vector<vl> res = generateSubsets(v);
    ll n = res.size();
    FOR(i, n)
    {
        res.pb(res[i]);
        res.back().pb(last);
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

vector<bool> prime;
void sieve_init(ll n)
{
    prime.clear();
    prime.resize(n + 1);
    prime[2] = true;
    for (ll i = 3; i <= n; i += 2)
    {
        prime[i] = true;
    }
    for (ll i = 3; i <= n; i += 2)
    {
        if (prime[i])
        {
            for (ll j = i * i; j <= n; j += i * 2)
            {
                prime[j] = false;
            }
        }
    }
}

ll extended_euclid(ll a, ll b, ll &x, ll &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll gcd = extended_euclid(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return gcd;
}

ll mod_inverse(ll a, ll m)
{
    ll x, y;
    ll gcd = extended_euclid(a, m, x, y);
    if (gcd != 1)
    {
        return -1;
    }
    return (x % m + m) % m;
}

ll Chinese_remainder_theorem(vl &num, vl &rem)
{
    ll prod = 1;
    FOR(i, num.size())
    {
        prod *= num[i];
    }
    vl pp(num.size());
    FOR(i, num.size())
    {
        pp[i] = prod / num[i];
    }
    ll res = 0;
    FOR(i, num.size())
    {
        res = (res + rem[i] * pp[i] * mod_inverse(pp[i], num[i])) % prod;
    }
    return res;
}

vi mobius;
void mobius_init(ll n)
{
    vl sieve(n + 1, 1), prime_count(n + 1);
    mobius.clear();
    mobius.resize(n + 1);
    FORr(i, 2, n+1)
    {
        if (!prime_count[i])
        {
            for (ll j = i; j <= n; j += i)
            {
                prime_count[j]++;
                sieve[j] *= i;
            }
        }
    }
    FOR(i, n+1)
    {
        if (sieve[i] == i)
        {
            if (prime_count[i] & 1)
            {
                mobius[i] = -1;
            }
            else
            {
                mobius[i] = 1;
            }
        }
        else
        {
            mobius[i] = 0;
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
#define int ll
vi Count;
vii getNeighbours(vector<vi>&mat,int x,int y){
    pii up=make_pair(x-1,y);
    pii down=make_pair(x+1,y);
    pii left=make_pair(x,y-1);
    pii right=make_pair(x,y+1);
    vii neighbours;
    if(up.first>=0 && up.second>=0&&mat[up.first][up.second]!=0){
        neighbours.push_back(up);
    }
    if(down.first<mat.size() && down.second>=0&&mat[down.first][down.second]!=0){
        neighbours.push_back(down);
    }
    if(left.first>=0 && left.second>=0&&mat[left.first][left.second]!=0){
        neighbours.push_back(left);
    }
    if(right.first>=0 && right.second<mat[0].size()&&mat[right.first][right.second]!=0){
        neighbours.push_back(right);
    }
    return neighbours;
}
void dfs(vector<vi>&mat,int x,int y,int c){
    mat[x][y]=c;
    Count[c]++;
    vii neighbours=getNeighbours(mat,x,y);
    for(auto neighbour:neighbours){
        if(mat[neighbour.first][neighbour.second]==1){
            dfs(mat,neighbour.first,neighbour.second,c);
        }
    }
}
void solve()
{
    int n,m;
    cin>>n>>m;
    vector<vi>mat(n);
    FOR(i,n){
        mat[i].resize(m);
        FOR(j,m){
            cin>>mat[i][j];
        }
    }
    int cnt=1;
    Count.clear();
    Count.resize(1000001);
    FOR(i,n){
        FOR(j,m){
            if(mat[i][j]==1){
                cnt++;
                dfs(mat,i,j,cnt);
            }
        }
    }
    // FOR(i,n){
    //     FOR(j,m){
    //         cout<<mat[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    ll ans=*max_element(all(Count));
    FOR(i,n){
        FOR(j,m){
            if(mat[i][j]==0){
                vii neighbours=getNeighbours(mat,i,j);
                set<int>neighValues;
                for(auto n:neighbours){
                    neighValues.insert(mat[n.first][n.second]);
                }
                if(neighValues.size()>1){
                    int c=0;
                    for(auto n:neighValues){
                        c+=(Count[n]);
                    }
                    if(c>ans){
                        ans=c;
                    }
                }
            }
        }
    }
    cout<<min(ans+1,n*m);
}