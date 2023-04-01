#include <bits/stdc++.h>
using namespace std;

int LongestMountain(vector<int>& arr)
{
	int n = arr.size();
	if (n < 3)
		return 0;
	int ans = 0;
	for (int i = 1; i <= n - 2;) {
		if (arr[i] > arr[i - 1] and arr[i] > arr[i + 1]) {
			int count = 0;
			int j = i; 
			while (arr[j] > arr[j - 1] and j > 0)
				count++, j--;
			while (arr[i] > arr[i + 1] and i <= n - 2)
				count++, i++;
			ans = max(ans, count);
		}
		else
			i++;
	}
	if (ans > 0)
		return ans + 1;
	return ans;
}

int main()
{
	vector<int> d
		= { 1, 3, 1, 4, 5, 6, 7, 8, 9, 8, 7, 6, 5 };
	cout << LongestMountain(d) << endl;
	return 0;
}