int cutLogs(int k, int n)
{
    // Base case
    if (n == 0)
        return 0;

    if (k == 0)
        return 1;

    int ans = n;

    for (int i = 1; i <= n; i++)
    {
        int noCut = cutLogs(k - 1, i - 1);
        int Cut = cutLogs(k, n - i);
        ans = min(ans, max(noCut, Cut));
    }

    return ans + 1;
}

#include <bits/stdc++.h>
int f(int k, int n, vector<vector<int>> &dp)
{

    // Base case
    if (dp[k][n] != -1)
        return dp[k][n];
    if (n == 0)
        return 0;

    if (k == 0)
        return 1;

    int ans = n;

    for (int i = 1; i <= n; i++)
    {
        int noCut = f(k - 1, i - 1, dp);
        int Cut = f(k, n - i, dp);
        ans = min(ans, max(noCut, Cut));
    }

    return dp[k][n] = ans + 1;
}
int cutLogs(int k, int n)
{
    vector<vector<int>> dp(k + 1, vector<int>(n + 1, -1));
    return f(k, n, dp);
}

#include <bits/stdc++.h>

int cutLogs(int i, int j)
{
    vector<vector<int>> dp(i + 1, vector<int>(j + 1, 0));
    // base case
    for (int n = 0; n <= j; n++)
    {
        dp[0][n] = n;
    }
    // loops
    for (int k = 1; k <= i; k++)
    {
        for (int n = 1; n <= j; n++)
        {
            int ans = n;
            for (int t = 1; t <= n; t++)
            {
                int noCut = dp[k - 1][t - 1];
                int Cut = dp[k][n - t];
                ans = min(ans, max(noCut, Cut));
            }

            dp[k][n] = ans + 1;
        }
    }
    return dp[i][j];
}
