#include <stdio.h>
#include <stdlib.h>

int arr[] = {12, 13, 14, 10, 3, 5, 2, 4, 1};

void merge(int A[], int start, int mid, int end)
{
    int p = start, q = mid + 1;
    int Arr[end - start + 1], k = 0;
    for (int i = start; i <= end; i++)
    {
        if (p > mid)
            Arr[k++] = A[q++];

        else if (q > end)
            Arr[k++] = A[p++];

        else if (A[p] < A[q])
            Arr[k++] = A[p++];

        else
            Arr[k++] = A[q++];
    }
    for (int p = 0; p < k; p++)
    {
        A[start++] = Arr[p];
    }
}

void merge_sort(int A[], int start, int end)
{
    if (start < end)
    {
        int mid = (start + end) / 2;
        merge_sort(A, start, mid);
        merge_sort(A, mid + 1, end);
        merge(A, start, mid, end);
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
    merge_sort(arr, 0, N);
    for (int i = 0; i <= N; i++)
    {
        printf("%d ", arr[i]);
    }
}