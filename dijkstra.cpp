#include <iostream>
using namespace std;

int main()
{
    int V, E;
    cin >> V >> E;

    int u[100], v[100], w[100];

    // input edges
    for (int i = 0; i < E; i++)
    {
        cin >> u[i] >> v[i] >> w[i];
    }

    int dist[100], visited[100];

    // initialize
    for (int i = 0; i < V; i++)
    {
        dist[i] = 10000;   // INF
        visited[i] = 0;
    }

    int source = 0;
    dist[source] = 0;

    // main Dijkstra
    for (int i = 0; i < V - 1; i++)
    {
        int minDist = 10000;
        int uNode = -1;

        // find minimum unvisited node
        for (int j = 0; j < V; j++)
        {
            if (!visited[j] && dist[j] < minDist)
            {
                minDist = dist[j];
                uNode = j;
            }
        }

        if (uNode == -1) break;

        visited[uNode] = 1;

        // relax edges
        for (int j = 0; j < E; j++)
        {
            if (u[j] == uNode && !visited[v[j]])
            {
                if (dist[u[j]] + w[j] < dist[v[j]])
                {
                    dist[v[j]] = dist[u[j]] + w[j];
                }
            }
        }
    }

    // print result
    for (int i = 0; i < V; i++)
    {
        cout << i << " = " << dist[i] << endl;
    }

    return 0;
}