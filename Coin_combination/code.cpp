#include <iostream>
#include <vector>
using namespace std;

int coinCombinations(vector<int>& denominations, int idx, int target) {
    if (target == 0) return 1;
    int ways = 0;
    for (int i = idx; i < denominations.size(); i++) {
        if (target - denominations[i] >= 0)
            ways += coinCombinations(denominations, i, target - denominations[i]);
    }
    return ways;
}


int main() {
    int n = 3;
    vector<int> denominations{1,2,5};
    int target = 11;
    int ways = coinCombinations(denominations, 0, target);
    cout << "Number of possible coin combinations are: " << ways << endl;
    return 0;
}
