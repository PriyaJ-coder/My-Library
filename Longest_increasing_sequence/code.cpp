// Given a set of integers and a sum, determine if there is a subset of the given set with sum equal to given sum.
#include <bits/stdc++.h>
using namespace std;

// 2000 is the max limit
int LIS[2000]; // LIS[n] only used

int max(int n)
{
    int temp = LIS[0];
    for (int i = 1; i < n; i++)
    {
        if (LIS[i] > temp)
        {
            temp = LIS[i];
        }
    }
    return temp;
}

int sol(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (a[i] > a[j] && LIS[j + 1] > LIS[i])
            {
                printf("if\n");
                LIS[i] = LIS[j] + 1;
            }

            printf("[");
            for (int x = 0; x < n; x++)
            {
                printf("%d ", LIS[x]);
            }
            printf("]");
            printf("\nCount-[%d][%d]\n\n", i, j);
        }
    }
    return max(n);
}

int main()
{
    // memset(LIS, 1, sizeof(LIS));
    int n = 6;
    int a[] = {5, 11, 3, 15, 30, 25};

    for (int i = 0; i < n; i++)
    {
        LIS[i] = 1;
    }
    cout << sol(a, n) << endl;
}
