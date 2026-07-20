#include <iostream>
#include <stack>

using namespace std;
int graph[100][100];
int revGraph[100][100];
bool visited[100];

stack<int> st;
int n, e;

// DFS on original graph
void dfs1(int node)
{
    visited[node] = true;

    for(int i = 0; i < n; i++)
    {
        if(graph[node][i] == 1 && !visited[i])
        {
            dfs1(i);
        }
    }

    st.push(node);
}


// DFS on reversed graph
void dfs2(int node)
{
    visited[node] = true;

    cout << node << " ";

    for(int i = 0; i < n; i++)
    {
        if(revGraph[node][i] == 1 && !visited[i])
        {
            dfs2(i);
        }
    }
}


int main ()
{
    cout << "Enter number of vertices and edges: ";
    cin >> n >> e;

cout << "Enter edges (u v):\n";

    for(int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;

        graph[u][v] = 1;
        revGraph[v][u] = 1;
    }

    // DFS on original graph
    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            dfs1(i);
        }
    }


//reset visited arry 
for (int i=0;i<n;i++)
{
    visited[i] = false;
}


//dfs on reversed graph
cout << "Strongly connected components are :\n";





while(!st.empty())
{
    int node = st.top();
    st.pop();

    if(!visited[node])
    {
        dfs2(node);
        cout << endl;
    }





}
}
