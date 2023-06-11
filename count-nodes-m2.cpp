#include<bits/stdc++.h>
using namespace std;
void dfs(unordered_map<int,vector<int>>&mp,vector<int>&vis,int node,int &count)
{
	vis[node]=true;
	count++;
	for(int nodes:mp[node])
	{
		if(!vis[nodes])
		dfs(mp,vis,nodes,count);
	}
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
	int count=0;
	dfs(mp,vis,3,count);
	cout<<count<<endl;
	
}