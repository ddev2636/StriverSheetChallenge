/*
    Time complexity: O(N)
    Space complexity: O(K)

    where 'N' is the total number of elements in the array and 'K' is the maximum number of replacements allowed from 0 to 1.
*/

#include <queue>

int longestSubSeg(vector<int> &arr, int n, int k)
{

    // Starting index of array under consideration.
    int l = 0;
    int max_len = 0;
    queue<int> q;
    // To store current size of the queue.
    int size = 0;

    // i decides current ending point, i.e. the right pointer.
    for (int r = 0; r < n; r++)
    {
        if (arr[r] == 0)
        {
            q.push(r);
            size++;
        }

        // Updating queue when its size becomes greater than k.
        if (size > k)
        {
            // Updating starting index of array under consideration.
            l = q.front() + 1;
            q.pop();
            size--;
        }

        max_len = max(max_len, r - l + 1);
    }

    return max_len;
}

// optimal approach
int longestSubSeg(vector<int> &arr, int n, int k)
{

    // Stores count of zero in the array under consideration.
    int cnt0 = 0;
    int l = 0;
    int maxLen = 0;

    // r decides current ending point, i.e. the right pointer.
    for (int r = 0; r < n; r++)
    {
        if (arr[r] == 0)
        {
            cnt0++;
        }

        // If there are more 0's move left pointer towards current ending point.
        while (cnt0 > k)
        {
            if (arr[l] == 0)
            {
                cnt0--;
            }

            l++;
        }

        maxLen = max(maxLen, r - l + 1);
    }

    return maxLen;
}