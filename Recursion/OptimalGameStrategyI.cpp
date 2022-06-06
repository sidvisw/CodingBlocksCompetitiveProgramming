#include <bits/stdc++.h>
using namespace std;
#define int long long
int getScore(vector<int> &v, int low, int high, int scoreTillNow)
{
    if (low >= high)
    {
        return scoreTillNow;
    }
    scoreTillNow += v[low];
    int s1 = getScore(v, low + 2, high, scoreTillNow);
    int s2 = getScore(v, low + 1, high - 1, scoreTillNow);
    int S1 = min(s1, s2);
    scoreTillNow -= v[low];
    scoreTillNow += v[high];
    s1 = getScore(v, low, high - 2, scoreTillNow);
    s2 = getScore(v, low + 1, high - 1, scoreTillNow);
    int S2 = min(s1, s2);
    scoreTillNow -= v[high];
    return max(S1, S2);
}
signed main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    cout << getScore(v, 0, n - 1, 0) << endl;
    return 0;
}