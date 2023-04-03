// Time Complexity: O(min(a,b))
// Auxiliary Space: O(1)

#include <bits/stdc++.h>
using namespace std;

int LCM(int a, int b)
{
    int greater = max(a, b);
    int smallest = min(a, b);
    for (int i = greater;; i += greater)
    {
        if (i % smallest == 0)
            return i;
    }
}

int main()
{
    int a = 10, b = 5;
    cout << "LCM of " << a << " and " << b << " is " << LCM(a, b);
    return 0;
}
