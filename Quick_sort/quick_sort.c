#include <stdio.h>
#include <stdlib.h>

int arr[] = {12, 13, 14, 10, 3, 5, 2, 4, 1};

void swap(int a, int b)
{
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

int partition(int A[], int start, int end)
{
    int i = start + 1;
    int piv = A[start];
    for (int j = start + 1; j <= end; j++)
    {
        if (A[j] < piv)
        {
            swap(i, j);
            i += 1;
        }
    }
    swap(start, i - 1);
    return i - 1;
}

void quick_sort(int A[], int start, int end)
{
    if (start < end)
    {
        int piv_pos = partition(A, start, end);
        quick_sort(A, start, piv_pos - 1);
        quick_sort(A, piv_pos + 1, end);
    }
}

void main()
{
    int N = 8;
    for (int i = 0; i <= N; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    quick_sort(arr, 0, N);
    for (int i = 0; i <= N; i++)
    {
        printf("%d ", arr[i]);
    }
}