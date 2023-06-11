#include<bits/stdc++.h>
using namespace std;
int dfs(unordered_map<int,vector<int>>&mp,vector<int>&vis,int node)
{
	vis[node]=true;
	int count=1;
	for(int nodes:mp[node])
	{
		if(!vis[nodes])
		count+=dfs(mp,vis,nodes);
	}
	return count;
}
int main()
{
	int n;
	cin>>n;
	unordered_map<int,vector<int>>mp;
	for(int i=1;i<=n;i++)
	{
		int u,v;
		cin>>u>>v;
		mp[u].push_back(v);
		mp[v].push_back(u);
	}
	vector<int>vis(n+1,0);
	cout<<dfs(mp,vis,3)<<endl;
	
	
}