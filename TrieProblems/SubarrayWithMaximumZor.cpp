// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++

class Node
{
public:
	Node *left, *right;
	Node()
	{
		left = right = NULL;
	}
};
class Trie
{
public:
	Node *root;
	Trie()
	{
		root = new Node;
	}
	void insert(int num)
	{
		Node *ptr = root;
		for (int i = 31; i >= 0; i--)
		{
			int bit = (1 << i) & num;
			if (bit)
			{
				if (ptr->right == NULL)
				{
					ptr->right = new Node;
				}
				ptr = ptr->right;
			}
			else
			{
				if (ptr->left == NULL)
				{
					ptr->left = new Node;
				}
				ptr = ptr->left;
			}
		}
	}
	int maxZor(int num)
	{
		Node *ptr = root;
		int ans = 0;
		for (int i = 31; i >= 0; i--)
		{
			int bit = (1 << i) & num;
			if (bit)
			{
				if (ptr->left == NULL)
				{
					ptr = ptr->right;
				}
				else
				{
					ans += (1 << i);
					ptr = ptr->left;
				}
			}
			else
			{
				if (ptr->right == NULL)
				{
					ptr = ptr->left;
				}
				else
				{
					ans += (1 << i);
					ptr = ptr->right;
				}
			}
		}
		return ans;
	}
};

class Solution{   
public:
    int maxSubarrayXOR(int N, int arr[]){    
        int cumZor[N];
		cumZor[0] = arr[0];
		for (int i = 1; i < N; i++){
			cumZor[i] = cumZor[i - 1] ^ arr[i];
		}
		Trie t;
		int MaxZor=0;
		for(int i=0;i<N;i++){
			t.insert(cumZor[i]);
			MaxZor=max({MaxZor,cumZor[i],t.maxZor(cumZor[i])});
		}
		return MaxZor;
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t=1;
    // cin>>t;
    while(t--)
    {
        int N, X;
        cin >> N;
        int arr[N];
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }

        Solution ob;
        cout << ob.maxSubarrayXOR(N, arr) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends