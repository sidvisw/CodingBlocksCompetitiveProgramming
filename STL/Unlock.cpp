#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    vector<int> index(n + 1);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        index[a[i]] = i;
    }
    int i = n;
    while (k > 0 && i > 0)
    {
        if (index[i] != n - i)
        {
            int temp1=index[i];
            int temp2=index[a[n-i]];
            swap(index[i], index[a[n - i]]);
            swap(a[temp1], a[temp2]);
            k--;
        }
        i--;
    }
    vector<int> ans(n);
    for (int i = 1; i <= n; i++)
    {
        ans[index[i]] = i;
    }
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}