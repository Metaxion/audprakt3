//
// Created by marce on 20.11.2021.
//

#include "sort.h"

void selectionSort(int *array) {
    int i, j, min, t;

    for (i = 1; i < ARRAYSIZE; i++)
    {
        min = i;
        for (j = i + 1; j < ARRAYSIZE; j++)
            if (array[j] < array[min]) min = j;
        t = array[min]; array[min] = array[i]; array[i] = t;
    }

}

