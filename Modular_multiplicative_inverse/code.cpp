#include <bits/stdc++.h>
using namespace std;

int modInverse(int A, int M)
{
    for (int X = 1; X < M; X++)
        if (((A % M) * (X % M)) % M == 1)
            return X;

    return 0;
}

int main()
{
    int A = 3, M = 11;
    cout << modInverse(A, M);
    return 0;
}