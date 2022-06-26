// { Driver Code Starts
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
		unordered_set<int> s;
		for (int i = 0; i < N; i++)
		{
			s.insert(arr[i]);
		}
		int maxLen = 0;
		for (auto x : s)
		{
			int curLen = 1;
			if (s.find(x - 1) == s.end())
			{
				while (s.find(x + 1) != s.end())
				{
					curLen++;
					x++;
				}
			}
			maxLen = max(maxLen, curLen);
		}
		return maxLen;
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