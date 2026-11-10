
#include <iostream>
#include <vector>
#include <stack>
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
    stack<int> s;

    s.push(start);

    cout << "\nDFS Iterative Traversal: ";

    while (!s.empty()) {
        int current = s.top();
        s.pop();

        if (!visited[current]) {
            visited[current] = true;
            cout << current << " ";

            // Reverse insertion preserves recursive order
            for (int i = adj[current].size() - 1; i >= 0; i--) {
                int neighbour = adj[current][i];

                if (!visited[neighbour]) {
                    s.push(neighbour);
                }
            }
        }
    }

    return 0;
}
