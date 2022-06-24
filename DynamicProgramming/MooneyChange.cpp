#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD=1e9+7;
int *dp;
signed main() {
	int t;
	cin>>t;
	while(t--){
		int m;
		cin>>m;
		vector<int> a(m+1);
		for(int i=1;i<=m;i++){
			cin>>a[i];
		}
		int n;
		cin>>n;
		dp=new int[n+1];
		dp[0]=1;
		for(int i=1;i<=n;i++){
			dp[i]=0;
		}
		for(int j=1;j<=m;j++){
			for(int i=1;i<=n;i++){
				if(i>=a[j]){
					dp[i]=(dp[i]+dp[i-a[j]])%MOD;
				}
			}
		}
		cout<<dp[n]<<endl;
		delete [] dp;
	}
	return 0;
}