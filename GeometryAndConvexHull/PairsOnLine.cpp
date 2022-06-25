#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n,m,c;
    cin>>n>>m>>c;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    int cnt=0;
    for(int i=0;i<n;i++){
        int x=v[i];
        int y=m*x+c;
        if(binary_search(v.begin(),v.end(),y)){
            if(x!=y){
                cnt+=upper_bound(v.begin(),v.end(),y)-lower_bound(v.begin(),v.end(),y);
            }
            else{
                int freq=upper_bound(v.begin(),v.end(),y)-lower_bound(v.begin(),v.end(),y);
                if(freq>1){
                    cnt+=upper_bound(v.begin(),v.end(),y)-lower_bound(v.begin(),v.end(),y)-1;
                }
            }
        }
    }
    cout<<cnt<<endl;
}