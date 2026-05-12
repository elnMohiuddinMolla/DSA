#include <iostream>
#include <climits>
using namespace std;

int main() {
    int n;
    cin >> n;

    int cost[100][100];
    int vis[100] = {0};

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> cost[i][j];

    vis[0] = 1;
    int edge = 0;
    int total = 0;

    cout << "MST edges:\n";

    while (edge < n - 1) {
        int min = INT_MAX;
        int a = -1, b = -1;

        for (int i = 0; i < n; i++) {
            if (vis[i]) {
                for (int j = 0; j < n; j++) {
                    if (!vis[j] && cost[i][j] && cost[i][j] < min) {
                        min = cost[i][j];
                        a = i;
                        b = j;
                    }
                }
            }
        }

        cout << a << " - " << b << " : " << min << endl;
        vis[b] = 1;
        total += min;
        edge++;
    }

    cout << "Total cost = " << total << endl;

    return 0;
}