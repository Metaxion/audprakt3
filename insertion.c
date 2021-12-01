#include "sort.h"

void insertionSort(int *array) {
    int i, j, v;

    for (i = 2; i < ARRAYSIZE; i++)// Das ganze Array ablaufen
    {
        v = array[i]; //Nehme Element v
        j = i;
        while (array[j-1] > v){ //Verschiebe alle Elemente bis v eingesetzt werden kann
            array[j] = array[j-1]; j--;
        }
        array[j] = v; //Setze v ein
    }
}
