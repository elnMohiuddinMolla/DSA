#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> graph[100];        // original graph
vector<int> reverseGraph[100]; // reversed graph

int visited[100];
stack<int> st;

// First DFS (store finishing order)
void dfs1(int node)
{
    visited[node] = 1;

    for (int i = 0; i < graph[node].size(); i++)
    {
        int neighbor = graph[node][i];

        if (visited[neighbor] == 0)
        {
            dfs1(neighbor);
        }
    }

    st.push(node);  // push after finishing
}

// Second DFS (on reversed graph)
void dfs2(int node)
{
    visited[node] = 1;
    cout << node << " ";

    for (int i = 0; i < reverseGraph[node].size(); i++)
    {
        int neighbor = reverseGraph[node][i];

        if (visited[neighbor] == 0)
        {
            dfs2(neighbor);
        }
    }
}

int main()
{
    int nodes, edges;
    cin >> nodes >> edges;

    // Input directed edges
    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);        // original edge
        reverseGraph[v].push_back(u); // reversed edge
    }

    // Step 1: First DFS
    for (int i = 0; i < nodes; i++)
        visited[i] = 0;

    for (int i = 0; i < nodes; i++)
    {
        if (visited[i] == 0)
            dfs1(i);
    }

    // Step 2: Reset visited
    for (int i = 0; i < nodes; i++)
        visited[i] = 0;

    cout << "Strongly Connected Components:\n";

    // Step 3: Process stack
    while (!st.empty())
    {
        int node = st.top();
        st.pop();

        if (visited[node] == 0)
        {
            dfs2(node);
            cout << endl;
        }
    }

    return 0;
}