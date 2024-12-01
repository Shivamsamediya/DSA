#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Function to perform DFS and push nodes to the stack in topological order
void dfs(int node, vector<vector<int>>& adjList, vector<bool>& visited, stack<int>& topoStack) {
    visited[node] = true;

    for (int neighbor : adjList[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adjList, visited, topoStack);
        }
    }

    // Once all the neighbors are visited, push the current node to the stack
    topoStack.push(node);
}

// Function to perform topological sort using DFS
vector<int> topologicalSort(int n, vector<vector<int>>& adjList) {
    vector<bool> visited(n, false);
    stack<int> topoStack;

    // Perform DFS for all nodes (in case the graph is disconnected)
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, adjList, visited, topoStack);
        }
    }

    // Store the result from the stack (which contains topological sort in reverse order)
    vector<int> topoOrder;
    while (!topoStack.empty()) {
        topoOrder.push_back(topoStack.top());
        topoStack.pop();
    }

    return topoOrder;
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

    cout << "Topological Order: ";
    for (int node : topoOrder) {
        cout << node << " ";
    }

    return 0;
}
