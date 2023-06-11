class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void dfs(vector<int> adj[], unordered_map<int,bool>& vis, vector<int>& ans, int src) {
        vis[src] = true;
        ans.push_back(src);
        for(auto i : adj[src]) {
            if(!vis[i]) {
                dfs(adj, vis, ans, i);
            }
        }
    }

    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        unordered_map<int,bool> vis;
        vector<int> ans;
        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                dfs(adj, vis, ans, i);
            }
        }
        return ans;
    }
};