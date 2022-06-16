// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int matrixMultiplication(int N, int arr[])
    {
        int n=N-1;
        int dp[N][N]={0};
        for(int j=2;j<=n;j++){
            for(int i=j-1;i>=0;i--){
                int ans=INT_MAX;
                for(int k=i;k<=j-1;k++){
                    ans=min(ans,dp[i][k]+dp[k+1][j]+arr[i-1]*arr[k]*arr[j]);
                }
                dp[i][j]=ans;
            }
        }
        return dp[1][n];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}  // } Driver Code Ends