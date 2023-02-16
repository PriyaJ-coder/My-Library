#include <stdio.h>
#include <stdlib.h>

long gcd(long a, long b) {
    if(a==0){
        return 0;
    }
    return gcd(b%a, a);
}

int main()
{
    //Insert values such that b>>a
    long res = gcd(32,9374);
    printf("RESULT: %ld", res );
    return 0;
}