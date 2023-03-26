#include <stdio.h>

int main()
{
	int rows, columns, number = 1, n = 5;
	for (rows = 0; rows <= n; rows++) {
		for (columns = 0; columns < rows; columns++) {
			printf("%d ", number);
			number++;
		}
		printf("\n");
	}
	return 0;
}
