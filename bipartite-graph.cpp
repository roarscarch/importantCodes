class Solution {
public:
    bool dfs(vector<vector<int>>& graph, bool* color, int* visited, int index) {
        visited[index] = 1;
        for (auto neighbour : graph[index]) {
            if (visited[neighbour] == 0) {
                visited[neighbour] = 1;
                color[neighbour] = !color[index];
                if (!dfs(graph, color, visited, neighbour)) {
                    return false;
                }
            } else {
                if (color[neighbour] == color[index]) {
                    return false;
                }
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        bool* color = new bool[n];
        int* visited = new int[n];
        for (int i = 0; i < n; i++) {
            color[i] = false;
            visited[i] = 0;
        }
        for (int i = 0; i < n; i++) {
            if (visited[i] == 0) {
                color[i] = false;
                if (!dfs(graph, color, visited, i)) {// false aye to turant return kar do lekin
                // true aye to loop karo
                    return false;
                }
            }
        }
        return true;
    }
};
