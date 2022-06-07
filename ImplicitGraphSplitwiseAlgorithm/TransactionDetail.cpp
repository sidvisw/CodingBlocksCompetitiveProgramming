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
/*Don't treat int as long long*/ #define int ll

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

void BinarySearch(vector<ll> &a, ll begin, ll end, ll key, ll &idx)
{
	if (begin > end)
	{
		return;
	}
	ll mid = (begin + end) / 2;
	if (a[mid] == key)
	{
		idx = mid;
		BinarySearch(a, begin, mid - 1, key, idx);
	}
	else if (a[mid] > key)
	{
		BinarySearch(a, begin, mid - 1, key, idx);
	}
	else
	{
		BinarySearch(a, mid + 1, end, key, idx);
	}
}

void Merge(vl &a, ll begin, ll mid, ll end)
{
	ll i = begin, j = mid + 1, k = begin;
	vl temp(end - begin + 1);
	while (i <= mid && j <= end)
	{
		if (a[i] < a[j])
		{
			temp[k++] = a[i++];
		}
		else
		{
			temp[k++] = a[j++];
		}
	}
	while (i <= mid)
	{
		temp[k++] = a[i++];
	}
	while (j <= end)
	{
		temp[k++] = a[j++];
	}
	FOR(i, temp.size())
	{
		a[begin + i] = temp[i];
	}
}
void MergeSort(vl &a, ll begin, ll end)
{
	if (begin < end)
	{
		ll mid = (begin + end) / 2;
		MergeSort(a, begin, mid);
		MergeSort(a, mid + 1, end);
		Merge(a, begin, mid, end);
	}
}

class Graph
{
public:
	ll vertices;
	vector<list<pll>> adjList;
	Graph(ll v)
	{
		vertices = v;
		adjList.resize(v + 1);
	}
	void addEdge(ll u, ll v, bool bidir = false, ll w = 1)
	{
		adjList[u].pb(mp(v, w));
		if (bidir)
		{
			adjList[v].pb(mp(u, w));
		}
	}
	void bfs(ll src)
	{
		vector<bool> visited(vertices + 1);
		queue<ll> q;
		q.push(src);
		visited[src] = true;
		while (!q.empty())
		{
			ll u = q.front();
			q.pop();
			cout << u << " ";
			for (auto v : adjList[u])
			{
				if (!visited[v.ff])
				{
					q.push(v.ff);
					visited[v.ff] = true;
				}
			}
		}
	}
	void dfs(ll src, vector<bool> &visited)
	{
		visited[src] = true;
		cout << src << " ";
		for (auto v : adjList[src])
		{
			if (!visited[v.ff])
			{
				dfs(v.ff, visited);
			}
		}
	}
	ll primsMST()
	{
		ll mst = 0;
		vector<bool> visited(vertices + 1);
		priority_queue<pll, vll, greater<pll>> pq;
		pq.push(mp(0, 1));
		while (!pq.empty())
		{
			pll minEdge = pq.top();
			pq.pop();
			if (!visited[minEdge.ss])
			{
				mst += minEdge.ff;
				visited[minEdge.ss] = true;
				for (auto v : adjList[minEdge.ss])
				{
					if (!visited[v.ff])
					{
						pq.push(mp(v.ss, v.ff));
					}
				}
			}
		}
		return mst;
	}
	vl dijkstra(ll src)
	{
		vl dist(vertices + 1, INF);
		set<pll> s;
		dist[src] = 0;
		s.insert(mp(0, src));
		while (!s.empty())
		{
			pll minEdge = *s.begin();
			s.erase(s.begin());
			for (auto v : adjList[minEdge.ss])
			{
				if (dist[v.ff] > dist[minEdge.ss] + v.ss)
				{
					auto it = s.find(mp(dist[v.ff], v.ff));
					if (it != s.end())
					{
						s.erase(it);
					}
					dist[v.ff] = dist[minEdge.ss] + v.ss;
					s.insert(mp(dist[v.ff], v.ff));
				}
			}
		}
		return dist;
	}
};
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
	FORe(i, t)
	{
		// cout << "Case #"<<i<<": ";
		solve();
		cout << endl;
	}

	return 0;
}

/*Your functions here*/

void solve()
{
	int n,m;
	cin>>n>>m;
	map<string,int>net;
	FOR(i,m){
		string u,v;int w;
		cin>>u>>v>>w;
		net[u]-=w;
		net[v]+=w;
	}
	multiset<pair<int,string>>s;
	for(auto &p:net){
		if(p.ss!=0){
			s.insert(mp(p.ss,p.ff));
		}
	}
	int cnt=0;
	while(!s.empty()){
		auto beg=s.begin();
		auto end=s.end();
		end--;
		int transaction=min(-beg->ff,end->ff);
		cout<<beg->ss<<" will pay Rs "<<transaction<<" to "<<end->ss<<"."<<endl;
		pair<int,string> debit=mp(beg->ff+transaction,beg->ss);
		pair<int,string> credit=mp(end->ff-transaction,end->ss);
		s.erase(beg);
		s.erase(end);
		if(debit.ff){
			s.insert(debit);
		}
		if(credit.ff){
			s.insert(credit);
		}
		cnt++;
	}
	cout<<cnt;
}