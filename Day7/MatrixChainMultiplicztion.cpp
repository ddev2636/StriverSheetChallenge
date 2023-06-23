#include <bits/stdc++.h>

int f(int i, int j, vector<int> &a, vector<vector<int>> &dp)
{
    if (dp[i][j] != -1)
        return dp[i][j];
    if (i == j)
        return 0;
    int ans = 1e9;
    for (int k = i; k < j; k++)
    { // Corrected loop condition
        int steps = a[i - 1] _ a[k] _ a[j] + f(i, k, a, dp) + f(k + 1, j, a, dp);
        ans = min(ans, steps);
    }
    return dp[i][j] = ans;
}

int matrixMultiplication(vector<int> &arr, int N)
{
    // Write your code here.
    vector<vector<int>> dp(N, vector<int>(N, -1));
    f(1, N - 1, arr, dp);
    return dp[1][N - 1];
}
