#include <bits/stdc++.h>
int editDistance(string str1, string str2)
{
    int n = str1.size();
    int m = str2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    // Base case
    for (int j = 0; j <= m; j++)
    {
        dp[0][j] = j;
    }
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = i;
    }

    // Loops
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                int del = dp[i - 1][j];
                int insert = dp[i][j - 1];
                int replace = dp[i - 1][j - 1];
                dp[i][j] = 1 + min(del, min(insert, replace));
            }
        }
    }
    return dp[n][m];
}