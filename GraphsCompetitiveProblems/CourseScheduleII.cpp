#include <bits/stdc++.h>
using namespace std;

#define N 2005
#define ll long long 
class Solution {
public:
    vector<int> adj[N];
    bool dfs(int cur,vector<bool>&vis,vector<int>&order,vector<bool>&stack){
        vis[cur]=1;
        stack[cur]=1;
        for(auto nbr:adj[cur]){
            if(!vis[nbr]){
                if(dfs(nbr,vis,order,stack))return 1;
            }
            else if(stack[nbr]){
                return 1;
            }
        }
        order.push_back(cur);
        stack[cur]=0;
        return 0;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        for(auto&edge:prerequisites){
            int u=edge[1];
            int v=edge[0];
            adj[u].push_back(v);
        }
        vector<int>order;
        vector<bool>vis(numCourses+1);
        vector<bool>stack(numCourses+1);
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(dfs(i,vis,order,stack)){
                    return vector<int>();
                }
            }
        }
        reverse(order.begin(),order.end());
        return order;
    }
};

int main()
{
	int n,m;
	cin>>n>>m;
	vector<vector<int>>prerequisites;
	for(int i=0;i<m;i++){
		vector<int>edge;
		int u,v;
		cin>>u>>v;
		edge.push_back(u);
		edge.push_back(v);
		prerequisites.push_back(edge);
	}
	Solution s;
	vector<int>order=s.findOrder(n,prerequisites);
	for(auto x:order){
		cout<<x<<" ";
	}

	return 0;
}