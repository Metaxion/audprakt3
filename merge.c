//
// Created by marce on 20.11.2021.
//
#include "main.h"

#include <stdio.h>

int b[ARRAYSIZE];

void mergesort (int* a, int l, int r)
{
    int i, j, k, m;

    if (r > l)
    {
        m = (r + l)/2;
        mergesort (a, l, m);
        mergesort (a, m+1, r);
        for (i = m+1; i > l; i--) b[i-1] = a[i-1];
        for (j = m; j < r; j++) b[r+m-j] = a[j+1];
        for (k = l; k <= r; k++)
            a[k] = (b[i] < b[j])? b[i++] : b[j--];
    }
}

void mergeSort(int *array) {
 mergesort(array, 1, ARRAYSIZE);
}
