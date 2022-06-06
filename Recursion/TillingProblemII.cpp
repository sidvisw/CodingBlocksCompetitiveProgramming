#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<int>dp;
signed main() {
	int t;
	cin>>t;
	while(t--){
		dp.clear();
		dp.resize(100001);
		int n,m;
		cin>>n>>m;
		if(m==1){
			cout<<1<<endl;
			continue;
		}
		for(int i=0;i<m;i++){
			dp[i]=1;
		}
		dp[m]=2;
		for(int i=m+1;i<=n;i++){
			dp[i]=(dp[i-1]+dp[i-m])%1000000007;
		}
		cout<<dp[n]<<endl;
	}
	return 0;
}