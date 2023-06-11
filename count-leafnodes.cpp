int countLeafNodes(int curr, vector<int>& visited, vector<vector<int>>& adjList) {
    visited[curr] = true;
    int leafCount = 0;
    for (int next : adjList[curr]) {
        if (!visited[next]) {
            leafCount += countLeafNodes(next, visited, adjList);
        }
    }
    if (leafCount == 0) {
        // Current node is a leaf node
        return 1;
    } else {
        return leafCount;
    }
}
