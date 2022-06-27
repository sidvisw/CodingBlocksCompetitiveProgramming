// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Node
{
public:
	char data;
	unordered_map<char, Node *> hash;
	int count;
	Node(char c)
	{
		data = c;
		count = 0;
	}
};
class Trie
{
public:
	Node *root;
	Trie()
	{
		root = new Node('\0');
	}
	void insert(string &s)
	{
		Node *ptr = root;
		ptr->count++;
		for (auto c : s)
		{
			if (ptr->hash.count(c))
			{
				ptr = ptr->hash[c];
			}
			else
			{
				ptr = ptr->hash[c] = new Node(c);
			}
			ptr->count++;
		}
	}
	string query(string &s)
	{
		string ans;
		Node *ptr = root;
		for (auto c : s)
		{
			ptr = ptr->hash[c];
			if (ptr->count == 1)
			{
				ans += c;
				return ans;
			}
			ans += c;
		}
		return ans;
	}
};
class Solution
{
public:
	vector<string> findPrefixes(string arr[], int n)
	{
		Trie t;
		for (int i = 0; i < n; i++)
		{
			t.insert(arr[i]);
		}
		vector<string> ans(n);
		for (int i = 0; i < n; i++)
		{
			ans[i] = t.query(arr[i]);
		}
		return ans;
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

		string arr[n];
		for (int i = 0; i < n; i++)
			cin >> arr[i];

		Solution ob;
		vector<string> ans = ob.findPrefixes(arr, n);

		for (int i = 0; i < ans.size(); i++)
			cout << ans[i] << " ";

		cout << "\n";
	}

	return 0;
}
// } Driver Code Ends