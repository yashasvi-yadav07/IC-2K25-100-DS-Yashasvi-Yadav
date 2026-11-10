
#include <iostream>
#include <vector>
#include <queue>
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

    int start;
    cout << "Enter starting vertex: ";
    cin >> start;

    if (start < 0 || start >= vertices) {
        cout << "Invalid starting vertex!";
        return 0;
    }

    bool visited[20] = {false};
    queue<int> q;

    visited[start] = true;
    q.push(start);

    cout << "\nBFS Traversal: ";

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        cout << current << " ";

        for (int neighbour : adj[current]) {
            if (!visited[neighbour]) {
                visited[neighbour] = true;
                q.push(neighbour);
            }
        }
    }

    return 0;
}
