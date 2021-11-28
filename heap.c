//
// Created by marce on 20.11.2021.
//

//
// Created by marce on 20.11.2021.
//
#include "main.h"

static int N;

void upheap (int k, int* a)
{
    int v;

    v = a[k]; a[0] = INT_MAX;
    while (a[k/2] <= v)
    { a[k] = a[k/2]; k = k/2; }
    a[k] = v;
}

void insert (int v, int* a)
{
    a[++N] = v;
    upheap (N, a);
}

void downheap (int k, int* a)
{
    int j, v;

    v = a[k];
    while (k <= N/2)
    {
        j = k+k;
        if (j < N && a[j] < a[j+1]) j++;
        if (v >= a[j]) break;
        a[k] = a[j]; k = j;
    }
    a[k] = v;
}

int removee (int* a)
{
    int v = a[1];

    a[1] = a[N--];
    downheap (1, a);
    return v;
}

void heapSort(int *array) {
    int k;
    N = 0;

    for (k = 1; k <= ARRAYSIZE-1; k++) insert (array[k], array);
    for (k = ARRAYSIZE-1; k >= 1; k--) array[k] = removee(array);
}
