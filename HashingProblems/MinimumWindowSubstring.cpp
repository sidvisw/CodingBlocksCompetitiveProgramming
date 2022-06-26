// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    bool isValidWindow(int pFreq[],int sFreq[]){
        for(int i=0;i<26;i++){
            if(sFreq[i]<pFreq[i]){
                return 0;
            }
        }
        return 1;
    }
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        int pFreq[26]={0},sFreq[26]={0};
        for(auto ch:p){
            pFreq[ch-'a']++;
        }
        pair<int,int>minWindow={-100000,100000};
        int i=0,j=0;
        sFreq[s[0]-'a']++;
        while(j<s.length()){
            if(isValidWindow(pFreq,sFreq)){
                if(minWindow.second-minWindow.first>j-i){
                    minWindow={i,j};
                }
                sFreq[s[i]-'a']--;
                i++;
            }
            else{
                j++;
                sFreq[s[j]-'a']++;
            }
        }
        string ans;
        if(minWindow==make_pair(-100000,100000))return "-1";
        for(int i=minWindow.first;i<=minWindow.second;i++){
            ans+=s[i];
        }
        return ans;
    }
};

// { Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends