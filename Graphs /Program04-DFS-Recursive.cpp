
#include <iostream>
#include <vector>
using namespace std;

vector<int> adj[20];
bool visited[20] = {false};

void DFS(int vertex) {
    visited[vertex] = true;
    cout << vertex << " ";

    for (int neighbour : adj[vertex]) {
        if (!visited[neighbour]) {
            DFS(neighbour);
        }
    }
}

int main() {
    int vertices, edges;

    cout << "Enter number of vertices: ";
    cin >> vertices;

    cout << "Enter number of edges: ";
    cin >> edges;

    cout << "Enter edges (u v):\n";

    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;

        if (u >= 0 && u < vertices &&
            v >= 0 && v < vertices) {
            adj[u].push_back(v);
            adj[v].push_back(u);
        } else {
            cout << "Invalid edge!\n";
            i--;
        }
    }

    int start;
    cout << "Enter starting vertex: ";
    cin >> start;

    if (start < 0 || start >= vertices) {
        cout << "Invalid starting vertex!";
        return 0;
    }

    cout << "\nDFS Recursive Traversal: ";
    DFS(start);

    return 0;
}
