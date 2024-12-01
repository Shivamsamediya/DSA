#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Function to detect a cycle using Kahn's Algorithm (BFS)
bool isCycle(int n, vector<vector<int>>& adjList) {
    vector<int> inDegree(n, 0);

    // Compute in-degree of all nodes
    for (int u = 0; u < n; u++) {
        for (int v : adjList[u]) {
            inDegree[v]++;
        }
    }

    // Queue to store all nodes with in-degree 0
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    int countVisitedNodes = 0;

    // BFS to perform topological sort
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        countVisitedNodes++;

        // Decrease the in-degree of all neighbors
        for (int neighbor : adjList[node]) {
            inDegree[neighbor]--;
            if (inDegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    // If the number of visited nodes is not equal to the total number of nodes, there's a cycle
    return countVisitedNodes != n;
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
        adjList[u].push_back(v);  // Directed graph (u -> v)
    }

    if (isCycle(n, adjList)) {
        cout << "Cycle detected in the graph!" << endl;
    } else {
        cout << "No cycle detected in the graph!" << endl;
    }

    return 0;
}
