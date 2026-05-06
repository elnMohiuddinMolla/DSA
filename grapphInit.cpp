#include <iostream>
#include <vector>
using namespace std;

vector<int> graph[100];

void printGraph ( vector<int>graph[],int n  )
{
    
for ( int i =0; i<n ; i++ )
{ cout <<i<<"--> ";
for ( int j=0 ; j< graph[i].size();j++)
{

    cout << graph [i][j]<<" ";
}
cout << endl;
}

}
int main()
{
int nodes , edges;
cin >> nodes >> edges ;

int u,v;

for ( int i =0; i < edges ; i++)
{
cin >>u >>v;

graph[u].push_back(v);
graph[v].push_back(u);

}

printGraph ( graph,5);




return 0;
}