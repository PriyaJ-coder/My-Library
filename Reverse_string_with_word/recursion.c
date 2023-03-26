#include <stdio.h>

void reverse(char *str)
{
    if (*str)
    {
        reverse(str + 1);
        printf("%c", *str);
    }
}

int main()
{
    char a[] = "APS Duty [24*7]";
    reverse(a);
    return 0;
}
