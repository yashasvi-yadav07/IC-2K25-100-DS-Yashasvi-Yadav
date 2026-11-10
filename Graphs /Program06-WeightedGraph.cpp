
#include <iostream>
using namespace std;

int main() {
    int vertices, edges;

    cout << "Enter number of vertices: ";
    cin >> vertices;

    int graph[20][20] = {0};

    cout << "Enter number of edges: ";
    cin >> edges;

    cout << "Enter edges (u v weight):\n";

    for (int i = 0; i < edges; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;

        if (u >= 0 && u < vertices &&
            v >= 0 && v < vertices &&
            weight > 0) {
            graph[u][v] = weight;
            graph[v][u] = weight;
        } else {
            cout << "Invalid edge!\n";
            i--;
        }
    }

    cout << "\nWeighted Graph (Adjacency Matrix):\n";

    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            cout << graph[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}
