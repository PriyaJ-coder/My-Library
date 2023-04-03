#include <bits/stdc++.h>
using namespace std;
#define MAX 100000

int countMinCoins(int X, int C[], int N)
{
    int dp[X + 1];
    dp[0] = 0;
    for (int i = 1; i <= X; i++)
    {
        dp[i] = INT_MAX;
    }
    for (int i = 1; i <= X; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (C[j] <= i && dp[i - C[j]] != INT_MAX)
            {
                dp[i] = min(dp[i], 1 + dp[i - C[j]]);
            }
        }
    }
    if (dp[X] == INT_MAX)
    {
        cout << "-1";
        return -1;
    }
    int i = X;
    while (i > 0)
    {
        for (int j = 0; j < N; j++)
        {
            if (i >= C[j] && dp[i - C[j]] == dp[i] - 1)
            {
                cout << C[j] << " ";
                i -= C[j];
                break;
            }
        }
    }
    return dp[X];
}

int main()
{
    int X = 21;
    int arr[] = {2, 3, 4, 5};
    int N = sizeof(arr) / sizeof(arr[0]);
    countMinCoins(X, arr, N);
    return 0;
}