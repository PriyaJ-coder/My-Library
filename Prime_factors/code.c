#include <stdio.h>

void FndPrm(int Number)
{
    int i, Count = 0;
    for (i = 2; i <= Number / 2; i++)
    {
        if (Number % i == 0)
        {
            Count++;
        }
    }
    if (Count == 0 && Number != 1)
    {
        printf("\n %d", Number);
    }
}

void FndFac(int Number)
{
    int i;
    for (i = 1; i <= Number; i++)
    {
        if (Number % i == 0)
        {
            FndPrm(i);
        }
    }
}

int main()
{
    int i, j, Number, count;
    printf("Enter any number to Find :  ");
    scanf("%d", &Number);
    printf("\n Prime Factors of a Given Number are : \n");
    FndFac(Number);
    return 0;
}