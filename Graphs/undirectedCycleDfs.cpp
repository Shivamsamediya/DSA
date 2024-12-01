#include <iostream>
#include <vector>

using namespace std;

// DFS helper function to detect a cycle
bool dfsCycleDetection(int node, int parent, vector<vector<int>>& adjList, vector<bool>& visited) {
    visited[node] = true;
    
    // Explore all adjacent nodes
    for (int neighbor : adjList[node]) {
        // If the neighbor is not visited, continue DFS
        if (!visited[neighbor]) {
            if (dfsCycleDetection(neighbor, node, adjList, visited)) {
                return true;
            }
        }
        // If visited and the neighbor is not the parent, a cycle is found
        else if (neighbor != parent) {
            return true;
        }
    }
    return false;
}

bool isCycle(int n, vector<vector<int>>& adjList) {
    vector<bool> visited(n, false);
    
    // Check for cycles in every component of the graph
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfsCycleDetection(i, -1, adjList, visited)) {
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
        adjList[v].push_back(u); // Undirected graph, so add both edges
    }

    if (isCycle(n, adjList)) {
        cout << "Cycle detected in the graph!" << endl;
    } else {
        cout << "No cycle detected in the graph!" << endl;
    }

    return 0;
}
