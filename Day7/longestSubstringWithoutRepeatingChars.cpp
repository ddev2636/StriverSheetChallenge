#include <bits/stdc++.h>
using namespace std;

int uniqueSubstrings(string input)
{
    int n = input.size();
    vector<pair<bool, int>> alphabets(26, {false, -1});
    int size = 0;
    int maxi = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        if (alphabets[input[i] - 'a'].first == false)
        {
            alphabets[input[i] - 'a'].first = true;
            alphabets[input[i] - 'a'].second = i;
            size++;
        }
        else
        {
            int temp = alphabets[input[i] - 'a'].second;
            int cnt = 0;

            for (int j = 0; j < 26; j++)
            {
                if (alphabets[j].second < temp)
                {
                    alphabets[j].first = false;
                    alphabets[j].second = -1;
                }
                else if (alphabets[j].second > temp)
                {
                    cnt++;
                }
                else
                {
                    alphabets[j].second = i;
                }
            }

            size = cnt + 1;
        }

        maxi = max(size, maxi);
    }

    return maxi;
}
