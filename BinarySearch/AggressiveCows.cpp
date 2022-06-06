#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
bool isPossible(vector<int> v, int dist, int cows)
{
    int prev = v[0];
    cows--;
    int curr;
    for (int i = 1; i < v.size() && cows != 0; i++)
    {
        curr = v[i];
        if (curr - prev >= dist)
        {
            prev = curr;
            cows--;
        }
    }
    if (cows == 0)
        return true;
    return false;
}
void calcMinDist(vector<int> v, int beg, int end, int c, int &ans)
{
    if (beg == end)
    {
        if (isPossible(v, beg, c))
        {
            ans = beg;
            return;
        }
        return;
    }
    int mid = (beg + end) / 2;
    if (isPossible(v, mid, c))
    {
        ans = mid;
        calcMinDist(v, mid + 1, end, c, ans);
        return;
    }
    calcMinDist(v, beg, mid - 1, c, ans);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);

    int t;
    cin >> t;
    while (t--)
    {
        int n, c;
        cin >> n >> c;
        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            int no;
            cin >> no;
            v.push_back(no);
        }
        sort(v.begin(), v.end());
        int ans = 0;
        calcMinDist(v, 1, v[v.size() - 1] - v[0], c, ans);
        cout << ans << endl;
    }

    return 0;
}