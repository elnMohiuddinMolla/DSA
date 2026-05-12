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

    int dist[100];

    // initialize distance
    for (int i = 0; i < V; i++)
    {
        dist[i] = 10000;
    }

    int source = 0;
    dist[source] = 0;

    // relaxation step
    for (int i = 0; i < V - 1; i++)
    {
        for (int j = 0; j < E; j++)
        {
            if (dist[u[j]] != 10000 &&
                dist[u[j]] + w[j] < dist[v[j]])
            {
                dist[v[j]] = dist[u[j]] + w[j];
            }
        }
    }

    // check negative cycle
    for (int j = 0; j < E; j++)
    {
        if (dist[u[j]] != 10000 &&
            dist[u[j]] + w[j] < dist[v[j]])
        {
            cout << "Negative cycle exists";
            return 0;
        }
    }

    // print result
    for (int i = 0; i < V; i++)
    {
        cout << i << " = " << dist[i] << endl;
    }

    return 0;
}