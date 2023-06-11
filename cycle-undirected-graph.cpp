//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    // sirf ek baat yad rakhna 
    // jo node tum visit kar rahe ho agar wo visited hai but next node uska
    bool bfs(vector<bool>&vis,vector<int> adj[],int src)
    {
        queue<pair<int,int>> q;
        q.push({src,-1});
        vis[src]=1;
        while(!q.empty())
        {
            auto front=q.front();
            int source=front.first;
            int parent=front.second;
            q.pop();
            for(auto it:adj[source])
            {
                if(!vis[it])
                {
                    vis[it]=true;
                    q.push({it,source});
                }
            else if(it!=parent)
            return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        bool ans=1;
        vector<bool>vis(V,0);
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            if(bfs(vis,adj,i))
            return true;
        }
       
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends