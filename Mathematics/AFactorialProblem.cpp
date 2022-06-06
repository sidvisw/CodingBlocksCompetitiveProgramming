#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int ans = INT_MAX;
        int k_copy = k;
        for (int i = 2; i <= sqrt(k_copy) + 1; i++)
        {
            int occ = 0;
            while (k % i == 0)
            {
                occ++;
                k /= i;
            }
            if (occ > 0)
            {
                int prod = i;
                int cnt = 0;
                while (n / prod != 0)
                {
                    cnt += n / prod;
                    prod *= i;
                }
                ans = min(ans, cnt / occ);
            }
        }
        if (k > 1)
        {
            int prod = k;
            int cnt = 0;
            while (n / prod != 0)
            {
                cnt += n / prod;
                prod *= k;
            }
            ans = min(ans, cnt);
        }
        if (ans == INT_MAX)
        {
            cout << 0 << endl;
        }
        else
        {
            cout << ans << endl;
        }
    }
    return 0;
}