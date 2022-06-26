// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        int prev=0,maxLen=0;;
        unordered_map<int,int>m;
        for(int i=0;i<N;i++){
            prev+=A[i];
            if(prev==K){
                maxLen=max(maxLen,i+1);
            }
            if(m.find(prev-K)!=m.end()){
                maxLen=max(maxLen,i-m[prev-K]);
            }
            if(m.find(prev)==m.end()){
                m[prev]=i;
            }
        }
        return maxLen;
    } 

};

// { Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends