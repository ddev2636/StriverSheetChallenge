string longestCommonPrefix(vector<string> &arr, int n)
{
    // Write your code here
    string ans = arr[0];
    for (int i = 1; i < n; i++)
    {
        string temp = "";
        for (int j = 0; j < min(arr[i].size(), ans.size()); j++)
        {
            if (arr[i][j] == ans[j])
                temp += ans[j];
        }
        ans = temp;
        if (ans == "")
            break;
    }
    return ans;
}
