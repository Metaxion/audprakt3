#include "sort.h"

void quickSortt (int* a, int l, int r)
{
    int v, i, j, t;

    if (r > l)
    {
        //v = a[(l+r+1)/2];
        v = a[r]; // Pivot Element liegt am rechten Rand
        i = l-1; // i gleich linker Rand
        j = r; // j gleich rechter Rand
        for (;;)
        {
            while (a[++i] < v) ; //Setze i solange hoch bis Element kleiner Pivot gefunden ist
            while (a[--j] > v) ; //Setze j solange runter bis Element groesser Pivot gefunden ist
            if (i >= j) break; // Wenn i groesser ist also sich nach j verschoben hat, dann Schleife beenden
            t = a[i]; a[i] = a[j]; a[j] = t; // Ansonsten wechsel Position von i und j
        }
        t = a[i]; a[i] = a[r]; a[r] = t; // Wechsel Position von i und r
        quickSortt (a, l, i-1); //Rekursiver Aufruf mit linken Rand bis i
        quickSortt (a, i+1, r); //Rekursive Aufruf mit i bis rechten Rand
    }
}


void quickSort(int *array) {
    quickSortt(array, 1, ARRAYSIZE-1);
}
