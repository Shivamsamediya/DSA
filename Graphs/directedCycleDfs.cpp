#include <iostream>
#include <vector>

using namespace std;

// Helper function for DFS-based cycle detection in a directed graph
bool dfsCycleDetection(int node, vector<vector<int>>& adjList, vector<bool>& visited, vector<bool>& recStack) {
    visited[node] = true;       // Mark the current node as visited
    recStack[node] = true;      // Mark it in the current recursion stack
    
    // Explore all adjacent nodes
    for (int neighbor : adjList[node]) {
        // If neighbor is not visited, continue DFS
        if (!visited[neighbor]) {
            if (dfsCycleDetection(neighbor, adjList, visited, recStack)) {
                return true;  // If cycle is found in the recursion
            }
        }
        // If neighbor is visited and in the recursion stack, there is a cycle
        else if (recStack[neighbor]) {
            return true;
        }
    }
    
    // Remove the node from the recursion stack as we backtrack
    recStack[node] = false;
    return false;
}

// Function to detect cycle in the directed graph
bool isCycle(int n, vector<vector<int>>& adjList) {
    vector<bool> visited(n, false);   // To mark visited nodes
    vector<bool> recStack(n, false);  // To keep track of nodes in the recursion stack
    
    // Check for cycles in all components of the graph
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfsCycleDetection(i, adjList, visited, recStack)) {
                return true;  // Cycle found
            }
        }
    }
    
    return false;  // No cycle found
}

int main() {
    int n, m;
    cout << "Enter the number of nodes and edges: ";
    cin >> n >> m;

    vector<vector<int>> adjList(n);

    cout << "Enter the edges (u -> v): " << endl;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v); // Directed graph (u -> v)
    }

    if (isCycle(n, adjList)) {
        cout << "Cycle detected in the graph!" << endl;
    } else {
        cout << "No cycle detected in the graph!" << endl;
    }

    return 0;
}
