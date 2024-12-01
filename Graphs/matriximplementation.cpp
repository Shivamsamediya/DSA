#include <iostream>
#include <vector>
using namespace std;

class Graph {
public:
    // Adjacency matrix
    vector<vector<int>> adjMatrix;
    int n;  // Number of vertices

    // Constructor to initialize the matrix
    Graph(int numVertices) {
        n = numVertices;
        adjMatrix.resize(n, vector<int>(n, 0));  // Initialize all cells to 0
    }

    // Function to add an edge from vertex u to vertex v
    void addEdge(int u, int v, int direction) {
        // dir=0: undirected, dir=1: directed

        // Add edge from u to v
        adjMatrix[u][v] = 1;

        if (direction == 0) {
            // For undirected graph, add edge from v to u
            adjMatrix[v][u] = 1;
        }
    }

    // Function to print the adjacency matrix
    void printGraph() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << adjMatrix[i][j] << " ";
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

    Graph g(n);  // Initialize graph with 'n' vertices

    for (int i = 0; i < m; i++) {
        int u, v, direction;
        cout << "Enter edge (u v direction): ";
        cin >> u >> v >> direction;

        // Check for valid vertices
        if (u < 0 || v < 0 || u >= n || v >= n) {
            cout << "Invalid vertex!" << endl;
            continue;  // Skip invalid input
        }

        g.addEdge(u, v, direction);
    }

    // Print the adjacency matrix representation of the graph
    cout << "Graph representation using adjacency matrix:" << endl;
    g.printGraph();

    return 0;
}
