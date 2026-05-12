#include <iostream>
#include <algorithm> 
using namespace std;

int main() {
    int n, m;

    // Get number of items and capacity from user
    cout << "Enter number of items: ";
    cin >> n;
    cout << "Enter knapsack capacity: ";
    cin >> m;

    // Arrays with a fixed maximum size to handle dynamic input
    int P[100]; 
    int wt[100];
    int K[100][100]; 

    // Input profits
    cout << "Enter " << n << " profits: ";
    P[0] = 0; // 0th index placeholder
    for (int i = 1; i <= n; i++) {
        cin >> P[i];
    }

    // Input weights
    cout << "Enter " << n << " weights: ";
    wt[0] = 0; // 0th index placeholder
    for (int i = 1; i <= n; i++) {
        cin >> wt[i];
    }

    // Nested loops to fill the DP table
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= m; w++) {
            
            // 1. Base case: If no items or weight capacity is 0
            if (i == 0 || w == 0) {
                K[i][w] = 0;
            }
            
            // 2. If current item weight is less than or equal to current capacity
            else if (wt[i] <= w) {
                K[i][w] = max(P[i] + K[i - 1][w - wt[i]], 
                              K[i - 1][w]);
            }
            
            // 3. If current item weight exceeds capacity, take the previous row's value
            else {
                K[i][w] = K[i - 1][w];
            }
        }
    }

    // Output the maximum profit
    cout << "Maximum Profit: " << K[n][m] << endl;

    return 0;
}