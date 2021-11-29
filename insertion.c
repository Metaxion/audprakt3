//
// Created by marce on 20.11.2021.
//
#include "main.h"

void insertionSort(int *array) {
    int i, j, v;

    for (i = 2; i < ARRAYSIZE; i++)
    {
        v = array[i]; j = i;
        while (array[j-1] > v)
        {array[j] = array[j-1]; j--;}
        array[j] = v;
    }
}
