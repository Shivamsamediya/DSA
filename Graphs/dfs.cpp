#include <iostream>
#include <vector>
using namespace std;

class Graph {
public:
    vector<vector<int>> adjList; // Adjacency list
    int n;  // Number of vertices

    // Constructor to initialize the graph
    Graph(int numVertices) {
        n = numVertices;
        adjList.resize(n);
    }

    // Function to add an edge
    void addEdge(int u, int v, bool direction) {
        adjList[u].push_back(v);
        if (!direction) {
            adjList[v].push_back(u);  // For undirected graph
        }
    }

    // Recursive DFS function
    void dfs(int start, vector<bool> &visited) {
        visited[start] = true;
        cout << start << " ";

        // Recur for all adjacent vertices
        for (int neighbor : adjList[start]) {
            if (!visited[neighbor]) {
                dfs(neighbor, visited);
            }
        }
    }

    // Wrapper function to start DFS
    void dfsOfGraph(int start) {
        vector<bool> visited(n, false); // Initialize visited vector
        dfs(start, visited);
        cout << endl;
    }
};

int main() {
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;

    Graph g(n);

    int m;
    cout << "Enter the number of edges: ";
    cin >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cout << "Enter edge (u v): ";
        cin >> u >> v;
        if (u >= 0 && u < n && v >= 0 && v < n) {
            g.addEdge(u, v, false);  // For undirected graph
        } else {
            cout << "Invalid edge!" << endl;
        }
    }

    cout << "DFS traversal starting from node 0: ";
    g.dfsOfGraph(0);

    return 0;
}
