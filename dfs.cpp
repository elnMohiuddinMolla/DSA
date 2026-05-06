#include <iostream>
using namespace std;

int graph[100][100];  // adjacency matrix
bool visited[100];

int n, e;

void dfs(int node)
{
    visited[node] = true;
    cout << node << " ";

    for(int i = 0; i < n; i++)
    {
        if(graph[node][i] == 1 && visited[i] == false)
        {
            dfs(i);
        }
    }
}

int main()
{
    cin >> n >> e;

    for(int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;

        graph[u][v] = 1;
        graph[v][u] = 1; // undirected
    }

    cout << "DFS Traversal: ";
    dfs(0);

    return 0;
}