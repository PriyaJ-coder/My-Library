#include <iostream>
using namespace std;

int max(int a, int b) { return (a > b)? a : b;}
int max(int a, int b, int c) { return max(a, max(b, c));}

int maxProd(int n)
{
    int val[n + 1];
    val[0] = val[1] = 0;

    for (int i = 1; i <= n; i++)
    {
        int max_val = 0;
        for (int j = 1; j <= i; j++)
            max_val = max(max_val, (i - j) * j, j * val[i - j]);
        val[i] = max_val;
    }
    return val[n];
}

int main()
{
    cout << "Maximum Product is " << maxProd(10);
    return 0;
}