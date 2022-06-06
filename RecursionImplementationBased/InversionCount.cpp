#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int mergeArrays(vector<int> &v, int beg, int end)
{
    int count = 0;
    int mid = (beg + end) / 2;
    vector<int> left, right;
    for (int i = beg; i <= mid; i++)
    {
        left.push_back(v[i]);
    }
    for (int i = mid + 1; i <= end; i++)
    {
        right.push_back(v[i]);
    }
    vector<int> ans;
    int i, j;
    for (i = 0, j = 0; i < left.size() && j < right.size();)
    {
        if (left[i] <= right[j])
        {
            ans.push_back(left[i]);
            i++;
        }
        else
        {
            ans.push_back(right[j]);
            j++;
            count += left.size() - i;
        }
    }
    while (i < left.size())
    {
        ans.push_back(left[i]);
        i++;
    }
    while (j < right.size())
    {
        ans.push_back(right[j]);
        j++;
    }
    for (int i = 0; i < ans.size(); i++)
    {
        v[beg + i] = ans[i];
    }
    return count;
}
int findInversion(vector<int> &v, int beg, int end)
{
    if (beg == end)
    {
        return 0;
    }
    int mid = (beg + end) / 2;
    int count1 = findInversion(v, beg, mid);
    int count2 = findInversion(v, mid + 1, end);
    int count3 = mergeArrays(v, beg, end);
    return count1 + count2 + count3;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int no;
        cin >> no;
        v.push_back(no);
    }
    int ans = findInversion(v, 0, n - 1);
    cout << ans << endl;

    return 0;
}