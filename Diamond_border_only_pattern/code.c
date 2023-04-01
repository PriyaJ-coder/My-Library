#include <stdio.h>

int main()
{
    int size = 5;
    for (int i = 1; i <= size; i++)
    {
        for (int j = size; j > i; j--)
        {
            printf(" ");
        }
        for (int k = 0; k < i * 2 - 1; k++)
        {
            if (k == 0 || k == 2 * i - 2)
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
    for (int i = 1; i < size; i++)
    {
        for (int j = 0; j < i; j++)
        {
            printf(" ");
        }
        for (int k = (size - i) * 2 - 1; k >= 1; k--)
        {
            if (k == 1 || k == (size - i) * 2 - 1)
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}