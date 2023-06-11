public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int>bfs;
        vector<int>vis(V+1,0);// 0 to V hai
        queue<int>q;
        q.push(0);
        vis[0]=1;
        while(!q.empty())
        {
            int front=q.front();
            q.pop();
            bfs.push_back(front);
            for(auto traversingNode:adj[front])// traversing into the adjacent of ur node
            {
                if(!vis[traversingNode])
                {
                    vis[traversingNode]=1;
                    q.push(traversingNode);
                }
            }

        }
         return bfs;
    }
};