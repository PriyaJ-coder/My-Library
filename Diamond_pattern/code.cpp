#include <bits/stdc++.h>
using namespace std;

void gotonextLine(int k, int i, int z)
{
    if (k == i)
        return;
    cout << "* ";
    gotonextLine(k + z, i, z);
}

void addblankSpaceInDiamond(int j, int i, int z)
{
    if (j == i)
        return;
    cout << " ";
    addblankSpaceInDiamond(j + z, i, z);
}

void upperDiamond(int row, int i)
{
    if (i > row)
        return;
    addblankSpaceInDiamond(row, i, -1);
    gotonextLine(0, i, 1);
    cout << endl;
    upperDiamond(row, i + 1);
}

void lowerDiamond(int row, int i)
{
    if (i > row)
        return;
    addblankSpaceInDiamond(0, i, 1);
    gotonextLine(row, i, -1);
    cout << endl;
    lowerDiamond(row, i + 1);
}

int main()
{
    int row;
    row = 5;
    upperDiamond(row, 0);
    lowerDiamond(row, 1);
    return 0;
}