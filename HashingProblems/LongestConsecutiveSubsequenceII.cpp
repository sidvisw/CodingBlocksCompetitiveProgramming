#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
	// arr[] : the input array
	// N : size of the array arr[]

	// Function to return length of longest subsequence of consecutive integers.
	int findLongestConseqSubseq(int arr[], int N)
	{
		unordered_map<int, int> m;
		for (int i = 0; i < N; i++)
		{
			if(m.find(arr[i])!=m.end())continue;
			if (m.find(arr[i] - 1) != m.end() && m.find(arr[i] + 1) != m.end())
			{
				int len1 = m[arr[i] - 1];
				int len2 = m[arr[i] + 1];
				int len = 1 + len1 + len2;
				m[arr[i] - len1] = len;
				m[arr[i] + len2] = len;
				m[arr[i]] = len;
			}
			else if (m.find(arr[i] - 1) != m.end())
			{
				int len1 = m[arr[i] - 1];
				int len = 1 + len1;
				m[arr[i] - len1] = len;
				m[arr[i]] = len;
			}
			else if (m.find(arr[i] + 1) != m.end())
			{
				int len2 = m[arr[i] + 1];
				int len = 1 + len2;
				m[arr[i] + len2] = len;
				m[arr[i]] = len;
			}
			else
			{
				m[arr[i]] = 1;
			}
		}
		int M = 0;
		for (auto p : m)
		{
			M = max(M, p.second);
		}
		return M;
	}
};

// { Driver Code Starts.

// Driver program
int main()
{
	int t, n, i, a[100001];
	cin >> t;
	while (t--)
	{
		cin >> n;
		for (i = 0; i < n; i++)
			cin >> a[i];
		Solution obj;
		cout << obj.findLongestConseqSubseq(a, n) << endl;
	}

	return 0;
} // } Driver Code Ends