// In this program, the ASCII values of each character in one string is found out and then compared with the ASCII values of the other string

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define NO_OF_CHARACTERS 26
bool Anagram(char *Test1, char *Test2)
{
    int Count1[NO_OF_CHARACTERS] = {0};
    int Count2[NO_OF_CHARACTERS] = {0};
    int r = 0;
    if (strlen(Test1) != strlen(Test2))
        return false;
    for (r = 0; Test1[r] && Test2[r]; r++)
    {
        Count1[Test1[r] - 97]++;
        Count2[Test2[r] - 97]++;
    }
    for (r = 0; r < NO_OF_CHARACTERS; r++)
        if (Count1[r] != Count2[r])
            return false;
    return true;
}
int main()
{
    char Test1[] = "gab1";
    char Test2[] = "brag";
    if (Anagram(Test1, Test2))
        printf("The two strings are anagram of each other");
    else
        printf("The two strings are not anagram of each other");
    return 0;
}