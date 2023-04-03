// Given a set of integers and a sum, determine if there is a subset of the given set with sum equal to given sum.
#include <bits/stdc++.h>
using namespace std;

// 2000 is the max limit
int ss[2000][2000]; // ss[n+1][sum+1] only used

int subsetSum(int a[], int n, int sum)
{
    if (sum == 0) // for target sum is 0
        return 1;
    if (n <= 0) // for no items
        return 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (a[i - 1] > j)
            {
                printf("2if\n");
                ss[i][j] = 0;
            }
            else
            {
                printf("Else\n");
                ss[i][j] = ss[i - 1][j - a[i - 1]];
            }
            if (ss[i - 1][j] == 1)
            {
                printf("1if\n");
                ss[i][j] = 1;
                // break;
            }
            printf("[\n");
            for (int x = 0; x <= n; x++)
            {
                for (int y = 0; y <= sum; y++)
                {
                    printf("%d ", ss[x][y]);
                }
                printf("\n");
            }
            printf("]");
            printf("\nCount-[%d][%d]\n\n", i, j);
            // printf("\nss->  %d", ss[i - 1][j - a[i - 2]]);
            // printf("\na[i-1]-> %d\n\n", a[i - 2]);
        }
    }
    return ss[n][sum];
}

int main()
{
    // memset(ss, 0, sizeof(ss));
    // int n = 5;
    // int a[] = {1, 5, 3, 7, 4};
    // int sum = 12;
    int n = 4;
    int a[] = {2, 3, 5, 7};
    int sum = 9;

    for (int i = 1; i <= sum; i++)
    {
        ss[0][i] = 0;
    }
    for (int i = 0; i <= n; i++)
    {
        ss[i][0] = 1;
    }

    if (subsetSum(a, n, sum))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
