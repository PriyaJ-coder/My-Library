#include <bits/stdc++.h>
using namespace std;

unsigned int swapBits(unsigned int x)
{
    for (int i = 0; i < 32; i += 2)
    {
        int i_bit = (x >> i) & 1;
        int i_1_bit = (x >> (i + 1)) & 1;
        x = x - (i_bit << i) - (i_1_bit << (i + 1)) + (i_bit << (i + 1)) + (i_1_bit << i);
    }
    return x;
}

int main()
{
    // 00010111
    unsigned int x = 23;
    cout << swapBits(x);
    return 0;
}