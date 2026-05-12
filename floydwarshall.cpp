#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int dist[100][100];

    // input adjacency matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> dist[i][j];
        }
    }

    // main Floyd-Warshall logic
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                if (dist[i][k] != 0 && dist[k][j] != 0) {
                    if (i == j) continue;

                    if (dist[i][i] == 0) dist[i][i] = 0;

                    if (dist[i][j] == 0)
                        dist[i][j] = dist[i][k] + dist[k][j];
                    else
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    // output shortest distance matrix
    cout << "Shortest path matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}