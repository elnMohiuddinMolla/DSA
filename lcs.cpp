#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string str1, str2;

    cout << "Enter first string: ";
    cin >> str1;

    cout << "Enter second string: ";
    cin >> str2;

    int n = str1.length();
    int m = str2.length();

    int dp[100][100];

    // Initialize first row and first column
    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;

    for (int j = 0; j <= m; j++)
        dp[0][j] = 0;

    // Fill DP table
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (str1[i - 1] == str2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    // Find LCS string
    string lcs = "";
    int i = n, j = m;

    while (i > 0 && j > 0)
    {
        if (str1[i - 1] == str2[j - 1])
        {
            lcs += str1[i - 1];
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
            i--;
        else
            j--;
    }

    reverse(lcs.begin(), lcs.end());

    cout << "Length of LCS = " << dp[n][m] << endl;
    cout << "LCS String = " << lcs << endl;

    return 0;
}