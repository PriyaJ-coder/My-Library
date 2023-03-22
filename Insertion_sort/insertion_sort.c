#include <stdio.h>
#include <stdlib.h>

int arr[] = {12, 13, 14, 10, 3, 5, 2, 4, 1};

void insertion_sort ( int A[ ] , int n) 
{
     for( int i = 0 ;i < n ; i++ ) {
    /*storing current element whose left side is checked for its 
             correct position .*/

      int temp = A[ i ];    
      int j = i;

       /* check whether the adjacent element in left side is greater or
            less than the current element. */

          while(  j > 0  && temp < A[ j -1]) {

           // moving the left side element to one position forward.
                A[ j ] = A[ j-1];   
                j= j - 1;

           }
         // moving current element to its  correct position.
           A[ j ] = temp;       
     }  
}

void main()
{
    int N = 9;
    for (int i = 0; i <= N; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    insertion_sort(arr, N);
    for (int i = 0; i <= N; i++)
    {
        printf("%d ", arr[i]);
    }
}