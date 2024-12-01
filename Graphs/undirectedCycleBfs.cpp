#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool bfsCycleDetection(int start, vector<vector<int>>& adjList, vector<bool>& visited) {
    // Pair of (node, parent) to track the BFS traversal and its parent
    queue<pair<int, int>> q;
    
    // Start with the first node (start) and assume its parent is -1 (no parent)
    q.push({start, -1});
    visited[start] = true;
    
    while (!q.empty()) {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();
        
        // Explore all adjacent nodes
        for (int neighbor : adjList[node]) {
            if (!visited[neighbor]) {
                // Mark as visited and push the neighbor with current node as its parent
                visited[neighbor] = true;
                q.push({neighbor, node});
            } else if (neighbor != parent) {
                // If the adjacent node is visited and is not the parent, cycle is detected
                return true;
            }
        }
    }
    
    return false;
}

bool isCycle(int n, vector<vector<int>>& adjList) {
    vector<bool> visited(n, false);
    
    // Check for cycle in each component of the graph
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            // If cycle is detected, return true
            if (bfsCycleDetection(i, adjList, visited)) {
                return true;
            }
        }
    }
    
    return false;
}

int main() {
    int n, m;
    cout << "Enter the number of nodes and edges: ";
    cin >> n >> m;

    vector<vector<int>> adjList(n);

    cout << "Enter the edges (u, v): " << endl;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u); // Because the graph is undirected
    }

    if (isCycle(n, adjList)) {
        cout << "Cycle detected in the graph!" << endl;
    } else {
        cout << "No cycle detected in the graph!" << endl;
    }

    return 0;
}
