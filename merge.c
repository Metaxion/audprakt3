#include "sort.h"

int b[ARRAYSIZE];

void mergesort (int* a, int l, int r)
{
    int i, j, k, m;

    if (r > l)
    {
        m = (r + l)/2; // Median berechnen
        mergesort (a, l, m); // Aufteilung in linken
        mergesort (a, m+1, r); // und rechten Teil und mit rekursivem Aufruf

        for (i = m+1; i > l; i--) b[i-1] = a[i-1]; // Von der Mitte bis linkem Rand alle Elemente in B Array

        for (j = m; j < r; j++) b[r+m-j] = a[j+1]; // Von der Mitte bis rechtem Rand alle Elemente in B Array

        for (k = l; k <= r; k++)
            a[k] = (b[i] < b[j])? b[i++] : b[j--]; //Belege A Array von vorne bis hinten
            //, schaue beide Teil von Array B an und vergleiche welches Element gerade das kleinste ist und setze es ein.
    }
}

void mergeSort(int *array) {
 mergesort(array, 1, ARRAYSIZE);
}
