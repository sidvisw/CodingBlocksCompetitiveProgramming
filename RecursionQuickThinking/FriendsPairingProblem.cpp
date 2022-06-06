#include<bits/stdc++.h>
using namespace std;
#define int long long
int f(int n){
	if(n<=1){
		return 1;
	}
	return f(n-1)+(n-1)*f(n-2);
}
signed main() {
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		cout<<f(n)<<endl;
	}
	return 0;
}
