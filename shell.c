#include "sort.h"

void shellSort(int *array) {
    int i, j, h, v;

    for (h = 1; h <= ARRAYSIZE/3; h = 3*h + 1) ;
    for ( ; h > 0; h /= 3)
        for (i = h + 1; i <= ARRAYSIZE; i++)
        {
            v = array[i]; j = i;
            while (j > h && array[j-h] > v)
            { array[j] = array[j-h]; j -= h;}
            array[j] = v;
        }
}

