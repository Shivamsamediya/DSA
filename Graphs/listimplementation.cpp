#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
using namespace std;

class Graph {
public:
    // Adjacency list where each index represents a vertex and contains a list of neighbors
    unordered_map<int, list<int>> adj;

    // Function to add an edge from vertex u to vertex v
    void addEdge(int u, int v, int direction) {
        // dir=0: undirected, dir=1: directed

        // Add edge from u to v
        adj[u].push_back(v);

        if (direction == 0) {
            // For undirected graph, add edge from v to u
            adj[v].push_back(u);
        }
    }

    // Function to print the adjacency list
    void printGraph() {
        for (const auto& i : adj) {
            cout << "Vertex " << i.first << ":";
            for (int neighbor : i.second) {
                cout << " -> " << neighbor;
            }
            cout << endl;
        }
    }
};

int main() {
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;

    int m;
    cout << "Enter the number of edges: ";
    cin >> m;

    Graph g;

    for (int i = 0; i < m; i++) {
        int u, v, direction;
        cout << "Enter edge (u v direction): ";
        cin >> u >> v >> direction;

        // Check if nodes are within the valid range
        if (u < 0 || v < 0 || u >= n || v >= n) {
            cout << "Invalid vertex!" << endl;
            continue;
        }

        // Create the graph with the specified direction
        g.addEdge(u, v, direction);
    }

    // Print the adjacency list representation of the graph
    cout << "Graph representation using adjacency list:" << endl;
    g.printGraph();

    return 0;
}
