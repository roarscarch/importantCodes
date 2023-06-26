Bellman Ford Algorithm
- The Bellman-Ford algorithm is a shortest path algorithm that finds the shortest path between a source vertex and all other vertices in a weighted directed graph. It works by repeatedly relaxing all the edges in the graph until it has found the shortest path to all vertices.

Here's how the Bellman-Ford algorithm works:

Initialize the distance to the source vertex as 0, and the distance to all other vertices as infinity.
Relax all the edges in the graph |V|-1 times, where |V| is the number of vertices in the graph. During each relaxation, the algorithm considers all the edges in the graph and updates the distance to the destination vertex if the current distance is greater than the distance to the source vertex plus the weight of the edge.
After |V|-1 relaxations, check for negative weight cycles. If any edge can further be reduced means there is a negative cycle in the graph present.
The time complexity of the Bellman-Ford algorithm is O(V * E)
vector<int> bellman_ford(int n, vector<vector<int>>& edges, int S) {
        vector<int> dist(n, 1e8);
        dist[S] = 0;
        for(int i = 1 ; i <= n - 1 ; i++){
            for(auto it : edges){
                int u = it[0];
                int v = it[1];
                int w = it[2];
                
                // Reachable and can be relaxed
                if(w + dist[u] < dist[v]){
                    dist[v] = w + dist[u];
                }
            }
        }
        
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            int w = it[2];
            
            // Reachable and can be relaxed hence negative cycle must be present
            if(w + dist[u] < dist[v]){
                return {-1};
            }
        }
        return dist;
    }