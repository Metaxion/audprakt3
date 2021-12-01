#include "sort.h"

void selectionSort(int *array) {
    int i, j, min, t;

    for (i = 1; i < ARRAYSIZE; i++) // Gehe das komplette Array ab
    {
        min = i; //Setze einen Wert aufs Minimum
        for (j = i + 1; j < ARRAYSIZE; j++) // Ueberpruefe im nicht sortierten Anteil des Arrays ob der gewaehlte Wert wirklich das Minimum ist
            if (array[j] < array[min]) min = j; // Ansonsten setze neuen Wert als Minimum
        t = array[min]; array[min] = array[i]; array[i] = t; //Setze das im nicht sortierten Anteil des Array gefundene Minimum an die nächste Stelle im sortierten Array
    }

}

