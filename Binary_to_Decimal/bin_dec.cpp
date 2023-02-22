#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

int bin_dec(string bin, long dec, long cnt, int mul)
{
    if (cnt == bin.length()-1)
    {
        return dec;
    }
    cnt = cnt + 1;
    char c = bin[cnt];
    char *str = &c;
    long i = atoi(str);
    dec+=i*pow(2,mul);
    return bin_dec(bin, dec, cnt, mul-1);
}

int main()
{
    string bin;
    cin >> bin;
    cout << bin_dec(bin, 0, -1, bin.length()-1);
    return 1;
}