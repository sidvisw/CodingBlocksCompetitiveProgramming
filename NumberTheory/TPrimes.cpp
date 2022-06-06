#include <bits/stdc++.h>
using namespace std;
#define N 1000000
typedef long long ll;
vector<bool> sieve;
set<ll> TPrimes;
void sieve_init()
{
    sieve.clear();
    sieve.resize(N + 1);
    sieve[2] = 1;
    TPrimes.insert(2 * 2);
    for (ll i = 3; i <= N; i += 2)
    {
        sieve[i] = 1;
    }
    for (ll i = 3; i <= N; i++)
    {
        if (sieve[i])
        {
            TPrimes.insert(i * i);
            for (ll j = i * i; j <= N; j += i)
            {
                sieve[j] = 0;
            }
        }
    }
    // cout<<"Hello"<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    sieve_init();
    int n;
    cin >> n;
    vector<ll> v;
    for (int i = 0; i < n; i++)
    {
        ll no;
        cin >> no;
        v.push_back(no);
    }
    for (int i = 0; i < n; i++)
    {
        if (TPrimes.find(v[i]) != TPrimes.end())
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}