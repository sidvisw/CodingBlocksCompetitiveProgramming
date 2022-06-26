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
		map<int, bool> m;
		for (int i = 0; i < N; i++)
		{
			m[arr[i]] = 1;
		}
		int maxLen = 1;
		int curLen = 1;
		for (auto it = next(m.begin()); it != m.end(); it++)
		{
			if (it->first - 1 == prev(it)->first)
			{
				curLen++;
			}
			else
			{
				maxLen = max(maxLen, curLen);
				curLen = 1;
			}
		}
		maxLen = max(maxLen, curLen);
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