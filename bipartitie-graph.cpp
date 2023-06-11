/* https://codeforces.com/contest/1144/problem/F */
#include<bits/stdc++.h>
using namespace std;
int n=2e5+5;
vector<bool>color(n,0);
vector<int>visited(n,0);
unordered_map<int,vector<int>>mp;
bool dfs(int source)
{
	//graph hai isliye parent se kaam nai chalega u will need visited array
	//agar bipartite graph nai hai to "NO" print karna hai
	// otherwise yes print kar ke uske color ko store karke 
	// print karna hai
	visited[source]=true;
	for(auto neighbour: mp[source])
	{
		if(!visited[neighbour])
		{
			visited[neighbour]=true;
			color[neighbour]=!color[source];
			if(!dfs(neighbour))
			return false;
		}
		else
		{
			if(color[neighbour]==color[source])
			return false;
		}
	}
	return true;
	
}
int main()
{
	int m;
	cin>>n>>m;
	color[1]=0;
	vector<vector<int>>edges;
	
	for(int i=1;i<=m;i++)
	{
		int u,v;
		cin>>u>>v;
		mp[u].push_back(v);
		mp[v].push_back(u);
		edges.push_back({u,v});
		
	}
	bool real =dfs(1);
	// input le liya and graph bana diya
	// abhi bas dfs chala hai
	if(real)
	{
		string ans="";
		cout<<"YES"<<endl;
		for(int i = 0;i<m;i++)
		{
			int u=edges[i][0];
			int v=edges[i][1];//u->v 1 
			ans+=to_string(color[v]);
		}
		cout<<ans<<endl;
	}
	else
	cout<<"NO"<<endl;
}