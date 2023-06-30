#include <bits/stdc++.h>
long countWaysToMakeChange(int *denominations, int n, int value)
{
    vector<vector<long>> dp(n, vector<long>(value + 1, 0));

    // Base case
    for (int ind = 0; ind < n; ind++)
    {
        dp[ind][0] = 1;
    }

    // Loop through remaining denominations and values
    for (int ind = 0; ind < n; ind++)
    {
        for (int val = 1; val <= value; val++)
        {
            // Option 1: Not take the current denomination
            long notTake = (ind > 0) ? dp[ind - 1][val] : 0;

            // Option 2: Take the current denomination
            long take = 0;
            if (denominations[ind] <= val)
            {
                take = dp[ind][val - denominations[ind]];
            }

            dp[ind][val] = take + notTake;
        }
    }

    return dp[n - 1][value];
}
