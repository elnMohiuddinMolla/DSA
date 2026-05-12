#include <iostream>
#include <algorithm>
using namespace std;

int parent[100];

// Find function (Disjoint Set)
int find(int x)
{
    if (parent[x] == x)
        return x;
    return parent[x] = find(parent[x]);
}

// Edge structure
struct Edge
{
    int u, v, w;
};

Edge e[100];

int main()
{
    int V, E;
    cin >> V >> E;

    // input edges
    for (int i = 0; i < E; i++)
    {
        cin >> e[i].u >> e[i].v >> e[i].w;
    }

    // sort edges by weight
    sort(e, e + E, [](Edge a, Edge b)
    {
        return a.w < b.w;
    });

    // initialize parent
    for (int i = 0; i < V; i++)
    {
        parent[i] = i;
    }

    int cost = 0;

    cout << "MST Edges:\n";

    // Kruskal algorithm
    for (int i = 0; i < E; i++)
    {
        int a = find(e[i].u);
        int b = find(e[i].v);

        if (a != b)
        {
            parent[a] = b;
            cost += e[i].w;

            cout << e[i].u << " - " << e[i].v << " : " << e[i].w << endl;
        }
    }

    cout << "Total cost = " << cost << endl;

    return 0;
}