#include <iostream>
using namespace std;

int main() {
    int V, E;
    cin >> V >> E;

    int u[100], v[100], w[100];

    // Input edges
    for (int i = 0; i < E; i++) {
        cin >> u[i] >> v[i] >> w[i];
    }

    int dist[100];

    // Initialize distances
    for (int i = 0; i < V; i++) {
        dist[i] = 100000; // infinity
    }

    int source = 0;
    dist[source] = 0;

    // Relax edges V-1 times
    for (int i = 0; i < V - 1; i++) {
        for (int j = 0; j < E; j++) {
            if (dist[u[j]] + w[j] < dist[v[j]]) {
                dist[v[j]] = dist[u[j]] + w[j];
            }
        }
    }

    // Check negative cycle
    for (int j = 0; j < E; j++) {
        if (dist[u[j]] + w[j] < dist[v[j]]) {
            cout << "Negative cycle exists\n";
            return 0;
        }
    }

    // Print result
    for (int i = 0; i < V; i++) {
        cout << "Distance to " << i << " = " << dist[i] << endl;
    }

    return 0;
}