
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int vertices, edges;

    cout << "Enter number of vertices: ";
    cin >> vertices;

    vector<int> adj[20];

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

    cout << "\nAdjacency List:\n";

    for (int i = 0; i < vertices; i++) {
        cout << i << " -> ";

        for (int j : adj[i]) {
            cout << j << " ";
        }

        cout << endl;
    }

    return 0;
}
