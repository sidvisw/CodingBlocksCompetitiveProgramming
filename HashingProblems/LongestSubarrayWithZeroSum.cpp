// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        int prev=0,maxLen=0;;
        unordered_map<int,int> m;
        for(int i=0;i<n;i++){
            prev+=A[i];
            if(prev==0){
                maxLen=max(maxLen,i+1);
            }
            if(m.find(prev)!=m.end()){
                maxLen=max(maxLen,i-m[prev]);
            }
            else{
                m[prev]=i;
            }
        }
        return maxLen;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}


  // } Driver Code Ends