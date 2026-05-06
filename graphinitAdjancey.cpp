#include <iostream>
using namespace std;

int main ()
{
int n, e;

cout <<"enter total node & edge ";
cin >> n>>e;
int graph [100][100];

  int u , v, w;
    cout << "enter mode1 node2 weight ";

for ( int i =1; i <=e ;i++)
{
    cin >> u>>v>>w;

graph[u][v] =w;
graph [v][u]=w; // undirected graph


}



cout << "weighted graph matrix : \n";

for (int i = 0; i < n; i++)
{
    for (int j= 0; j < n; j++)
    {
        cout << graph [i][j]<<" ";
    }
    cout << endl;
}









return 0;



}