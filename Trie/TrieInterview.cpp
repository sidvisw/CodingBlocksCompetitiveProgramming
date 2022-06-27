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

/*Don't treat int as long long?*/ #define int ll

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

/*-------------------------SOME IMPORTANT CLASSES-----------------------*/
class SegTree
{
public:
	ll n;
	vl lazy;
	vl tree;
	SegTree(ll n)
	{
		this->n = n;
		this->lazy = vl(4 * n + 1);
		this->tree = vl(4 * n + 1);
	}
	void build(vl &a, ll s, ll e, ll index)
	{
		if (s == e)
		{
			tree[index] = a[s];
			return;
		}
		ll mid = (s + e) / 2;
		build(a, s, mid, 2 * index);
		build(a, mid + 1, e, 2 * index + 1);
		tree[index] = tree[2 * index] + tree[2 * index + 1];
	}
	void update(ll s, ll e, ll l, ll r, ll val, ll index)
	{
		if (lazy[index] != 0)
		{
			tree[index] += lazy[index] * (e - s + 1);
			if (s != e)
			{
				lazy[2 * index] += lazy[index];
				lazy[2 * index + 1] += lazy[index];
			}
			lazy[index] = 0;
		}
		if (s > r || e < l)
		{
			return;
		}
		if (s >= l && e <= r)
		{
			tree[index] += val * (e - s + 1);
			if (s != e)
			{
				lazy[2 * index] += val;
				lazy[2 * index + 1] += val;
			}
			return;
		}
		ll mid = (s + e) / 2;
		update(s, mid, l, r, val, 2 * index);
		update(mid + 1, e, l, r, val, 2 * index + 1);
		tree[index] = tree[2 * index] + tree[2 * index + 1];
	}
	ll query(ll s, ll e, ll l, ll r, ll index)
	{
		if (lazy[index] != 0)
		{
			tree[index] += lazy[index] * (e - s + 1);
			if (s != e)
			{
				lazy[2 * index] += lazy[index];
				lazy[2 * index + 1] += lazy[index];
			}
			lazy[index] = 0;
		}
		if (s > r || e < l)
		{
			return 0;
		}
		if (s >= l && e <= r)
		{
			return tree[index];
		}
		ll mid = (s + e) / 2;
		ll left = query(s, mid, l, r, 2 * index);
		ll right = query(mid + 1, e, l, r, 2 * index + 1);
		return left + right;
	}
};

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
	void addEdge(ll u, ll v, bool bidir = true, ll w = 1)
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

class TrieNode
{
public:
	TrieNode*left,*right;
	TrieNode()
	{
		left=right=NULL;
	}
};
class Trie
{
public:
	TrieNode *root;
	Trie()
	{
		root = new TrieNode();
	}
	void insert(int num)
	{
		TrieNode *curr = root;
		for(int i=31;i>=0;i--){
			int bit=(1<<i)&num;
			if(bit){
				if(curr->right==NULL){
					curr->right=new TrieNode();
				}
				curr=curr->right;
			}
			else{
				if(curr->left==NULL){
					curr->left=new TrieNode();
				}
				curr=curr->left;
			}
		}
	}
	int maxZor(int num)
	{
		TrieNode *curr = root;
		int ans=0;
		for(int i=31;i>=0;i--){
			int bit=(1<<i)&num;
			if(bit){
				if(curr->left==NULL){
					curr=curr->right;
				}
				else{
					ans+=(1<<i);
					curr=curr->left;
				}
			}
			else{
				if(curr->right==NULL){
					curr=curr->left;
				}
				else{
					ans+=(1<<i);
					curr=curr->right;
				}
			}
		}
		return ans;
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
	// /*Is Single Test Case?*/ cin >> t;
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
	int n;
	cin>>n;
	vi a(n);
	FOR(i,n){
		cin>>a[i];
	}
	vi cumZorPrefix(n),cumZorSuffix(n);
	cumZorPrefix[0]=a[0];
	FOR(i,n-1){
		cumZorPrefix[i+1]=cumZorPrefix[i]^a[i+1];
	}
	cumZorSuffix[n-1]=a[n-1];
	FORrev(i,n-2){
		cumZorSuffix[i]=cumZorSuffix[i+1]^a[i];
	}
	Trie t1,t2;
	vi prefixMaxZor(n),suffixMaxZor(n);
	int maxPrefixZor=0,maxSuffixZor=0;
	FOR(i,n){
		t1.insert(cumZorPrefix[i]);
		maxPrefixZor=max({cumZorPrefix[i],maxPrefixZor,t1.maxZor(cumZorPrefix[i])});
		prefixMaxZor[i]=maxPrefixZor;
	}
	FORrev(i,n-1){
		t2.insert(cumZorSuffix[i]);
		maxSuffixZor=max({cumZorSuffix[i],maxSuffixZor,t2.maxZor(cumZorSuffix[i])});
		suffixMaxZor[i]=maxSuffixZor;
	}
	int ans=0;
	FOR(i,n-1){
		ans=max(ans,prefixMaxZor[i]+suffixMaxZor[i+1]);
	}
	cout<<ans;
}