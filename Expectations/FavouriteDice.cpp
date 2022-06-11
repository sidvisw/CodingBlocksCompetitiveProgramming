/*
COUPON COLLECTOR PROBLEM
-------------------------
Uncle Chips always distributes a coupon in packet of chips.
The coupon choosen for each pack is chosen randomly from a set
of 'n' distinct coupons. What is the expected number of chips packets
one must buy so that you get all 'n' distinct coupons?

Solution:
X_i = No of packets to buy to get the ith new coupon
E(X_i) = 1/p = n/(n-(i-1)) <- Bernaulli
p = (n-(i-1))/n
E(X) = E(X_1) + E(X_2) + ... + E(X_n)
     = n/n + n/(n-1) + ... + n/1
     = n(1 + 1/2 + ... + 1/n)
*/

#include <bits/stdc++.h>
using namespace std;

/*Your functions here*/

int main()
{
    /*Your code here*/
    int t;
    cin>>t;
    while(t--)
    {
        long double n;
        cin>>n;
        long double ans = 0;
        for(long long i=1;i<=n;i++){
            ans += 1.0/i;
        }
        cout<<setprecision(2)<<fixed<<ans*n<<endl;
    }
    return 0;
}