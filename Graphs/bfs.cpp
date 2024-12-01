#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
public:
    vector<vector<int>> adjList;
    int n;  // Number of vertices

    Graph(int numVertices) {
        n = numVertices;
        adjList.resize(n);
    }

    void addEdge(int u, int v, bool direction) {
        adjList[u].push_back(v);
        if (!direction) {
            adjList[v].push_back(u);  // For undirected graph
        }
    }

    void bfs(int start) {
        vector<bool> visited(n, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cout << node << " ";

            for (int neighbor : adjList[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        cout << endl;
    }
};

int main() {
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;

    Graph g(n);

    g.addEdge(0, 1, false);
    g.addEdge(0, 2, false);
    g.addEdge(1, 3, false);
    g.addEdge(2, 4, false);
    g.addEdge(2, 5, false);

    cout << "BFS traversal starting from node 0: ";
    g.bfs(0);

    return 0;
}
