pair<int, int> missingAndRepeating(vector<int> &a, int n)
{
    int missing = 0;
    int repeating = 0;

    // Finding the repeating number
    for (int i = 0; i < n; i++)
    {
        if (a[abs(a[i]) - 1] > 0)
        {
            a[abs(a[i]) - 1] = -a[abs(a[i]) - 1];
        }
        else
        {
            repeating = abs(a[i]);
        }
    }

    // Finding the missing number
    for (int i = 0; i < n; i++)
    {
        if (a[i] > 0)
        {
            missing = i + 1;
            break;
        }
    }

    return {missing, repeating};
}

// we can also use xor method