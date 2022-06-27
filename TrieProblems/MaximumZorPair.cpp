// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
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
class Solution
{
public:
	int max_xor(int arr[], int n)
	{
		Trie t;
		int MZor = 0;
		for (int i = 0; i < n; i++)
		{
			t.insert(arr[i]);
			MZor = max(MZor, t.maxZor(arr[i]));
		}
		return MZor;
	}
};

// { Driver Code Starts.
int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int n;
		cin >> n;

		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];

		Solution ob;
		cout << ob.max_xor(a, n) << endl;
	}
}

// } Driver Code Ends