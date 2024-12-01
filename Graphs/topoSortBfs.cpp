#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> topologicalSort(int n, vector<vector<int>>& adjList) {
    vector<int> inDegree(n, 0);
    vector<int> topoOrder;

    // Step 1: Calculate in-degrees of all nodes
    for (int i = 0; i < n; i++) {
        for (int neighbor : adjList[i]) {
            inDegree[neighbor]++;
        }
    }

    // Step 2: Push nodes with 0 in-degree into the queue
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    // Step 3: Process nodes with 0 in-degree
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        topoOrder.push_back(node);

        // For all neighbors of the current node
        for (int neighbor : adjList[node]) {
            inDegree[neighbor]--;  // Remove the edge

            // If in-degree of the neighbor becomes 0, add it to the queue
            if (inDegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    // If topoOrder contains all nodes, return it; otherwise, graph contains a cycle
    if (topoOrder.size() == n) {
        return topoOrder;
    } else {
        return {};  // Return an empty vector if there is a cycle (no topological sort possible)
    }
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

    vector<int> topoOrder = topologicalSort(n, adjList);

    if (topoOrder.empty()) {
        cout << "The graph has a cycle, so topological sorting is not possible." << endl;
    } else {
        cout << "Topological Order: ";
        for (int node : topoOrder) {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}
