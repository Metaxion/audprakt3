//
// Created by marce on 20.11.2021.
//

#ifndef AUDPRAKT3_SORT_H
#define AUDPRAKT3_SORT_H
#define ARRAYSIZE 21 // default 200001
#define SHOW_ARRAYS 0 // 0(dont show) oder 1 (show)

#include <limits.h>

void selectionSort(int *array);
void insertionSort(int *array);
void shellSort(int *array);
void quickSort(int *array);
void mergeSort(int *array);
void heapSort(int *array);
void printArray(int *array);

#endif //AUDPRAKT3_SORT_H
