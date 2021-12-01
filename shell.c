#include "sort.h"

void shellSort(int *array) {
    int i, j, h, v;

    for (h = 1; h <= ARRAYSIZE/3; h = 3*h + 1) ; // Schrittweite h festlegen, Unterteilung in 3 Bloecke
    for ( ; h > 0; h /= 3) { //Durchlauf der unterteilten Bloecke, vom Letzten bis zum Ersten
        for (i = h + 1; i <= ARRAYSIZE; i++) { //Jetzt Insertionsort beginnen mit letzten Block als erstes
            v = array[i]; //Nehme Element v
            j = i;
            while (j > h && array[j - h] > v) { //Verschiebe alle Elemente bis v eingesetzt werden kann
                array[j] = array[j - h];
                j -= h;
            }
            array[j] = v; //Setze v ein
        }
    }
}

