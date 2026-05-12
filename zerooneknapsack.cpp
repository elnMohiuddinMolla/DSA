#include <iostream>
#include <algorithm> 
using namespace std;

int main() {
    int n, m;

    // Input number of items and capacity
    cout << "Enter number of items: ";
    cin >> n;

    cout << "Enter knapsack capacity: ";
    cin >> m;

    int P[100];   // profits
    int wt[100];  // weights
    int K[100][100]; // DP table

    // Input profits
    cout << "Enter " << n << " profits: ";
    P[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> P[i];
    }

    // Input weights
    cout << "Enter " << n << " weights: ";
    wt[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> wt[i];
    }

    // Build DP table
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= m; w++) {

            if (i == 0 || w == 0) {
                K[i][w] = 0;
            }
            else if (wt[i] <= w) {
                K[i][w] = max(P[i] + K[i - 1][w - wt[i]],
                              K[i - 1][w]);
            }
            else {
                K[i][w] = K[i - 1][w];
            }
        }
    }

    // Output maximum profit
    cout << "\nMaximum Profit: " << K[n][m] << endl;

    // Backtracking to find selected items
    cout << "Selected items (1-based index): ";

    int i = n, w = m;

    while (i > 0 && w > 0) {
        if (K[i][w] != K[i - 1][w]) {
            cout << i << " ";
            w = w - wt[i];
        }
        i--;
    }

    cout << endl;

    return 0;
}