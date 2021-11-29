//
// Created by marce on 20.11.2021.
//
#include "main.h"

void quickSortt (int* a, int l, int r)
{
    int v, i, j, t;

    if (r > l)
    {
        v = a[(l+r+1)/2];

        i = l-1; j = r;
        for (;;)
        {
            while (a[++i] < v) ;
            while (a[--j] > v) ;
            if (i >= j) break;
            t = a[i]; a[i] = a[j]; a[j] = t;
        }
        t = a[i]; a[i] = a[r]; a[r] = t;
        quickSortt (a, l, i-1);
        quickSortt (a, i+1, r);
    }
}


void quickSort(int *array) {
    quickSortt(array, 1, ARRAYSIZE-1);
}
