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
    /*----------------------------------------------------------------------*/
    void
    solve();
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
struct subarray
{
    ll maxPrefixSum;
    ll maxSuffixSum;
    ll totalSum;
    ll maxSubarraySum;
};
void buildTree(vi &a, vector<subarray> &tree, int s, int e, int index)
{
    if (s == e)
    {
        tree[index].maxPrefixSum = a[s];
        tree[index].maxSuffixSum = a[s];
        tree[index].totalSum = a[s];
        tree[index].maxSubarraySum = a[s];
        return;
    }
    int mid = (s + e) / 2;
    buildTree(a, tree, s, mid, 2 * index);
    buildTree(a, tree, mid + 1, e, 2 * index + 1);
    tree[index].maxPrefixSum = max(tree[2 * index].maxPrefixSum, tree[2 * index].totalSum + tree[2 * index + 1].maxPrefixSum);
    tree[index].maxSuffixSum = max(tree[2 * index + 1].maxSuffixSum, tree[2 * index + 1].totalSum + tree[2 * index].maxSuffixSum);
    tree[index].totalSum = tree[2 * index].totalSum + tree[2 * index + 1].totalSum;
    tree[index].maxSubarraySum = max(max(tree[2 * index].maxSubarraySum, tree[2 * index + 1].maxSubarraySum), tree[2 * index].maxSuffixSum + tree[2 * index + 1].maxPrefixSum);
}
subarray query(vector<subarray> &tree, int s, int e, int l, int r, int index)
{
    if (s > r || e < l)
        return {INT_MIN, INT_MIN, INT_MIN, INT_MIN};
    if (s >= l && e <= r)
        return tree[index];
    int mid = (s + e) / 2;
    subarray left = query(tree, s, mid, l, r, 2 * index);
    subarray right = query(tree, mid + 1, e, l, r, 2 * index + 1);
    subarray ans;
    ans.maxPrefixSum = max(left.maxPrefixSum, left.totalSum + right.maxPrefixSum);
    ans.maxSuffixSum = max(right.maxSuffixSum, right.totalSum + left.maxSuffixSum);
    ans.totalSum = left.totalSum + right.totalSum;
    ans.maxSubarraySum = max(max(left.maxSubarraySum, right.maxSubarraySum), left.maxSuffixSum + right.maxPrefixSum);
    return ans;
}
void solve()
{
    int n;
    cin >> n;
    vi a(n);
    FOR(i, n)
    {
        cin >> a[i];
    }
    vector<subarray> tree(4 * n + 1);
    buildTree(a, tree, 0, n - 1, 1);
    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << query(tree, 0, n - 1, l - 1, r - 1, 1).maxSubarraySum << endl;
    }
}