class Solution {
public:
void dfs (  unordered_map<int, vector<int>>& adj,int source, unordered_map<int,bool>&vis)
{
    vis[source]=true;
    for(auto it:adj[source])
    {
        if(!vis[it])
        {
            vis[it]=true;
            dfs(adj,it,vis);
        }
    }
}
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int,bool>vis;
        unordered_map<int, vector<int>> graph;
        for (auto& edge : edges) {
            int a = edge[0], b = edge[1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        dfs(graph,source,vis);
        return vis[destination];
    }
};
//isse samaj mein ayaga ki graph banana kyun important hai