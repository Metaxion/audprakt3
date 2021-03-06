#include "main.h"

int *vergleichsArray;

int main() {
    int *randomArray = calloc(1, sizeof(int[ARRAYSIZE]));
    int *aufsteigendArray = calloc(1, sizeof(int[ARRAYSIZE]));
    int *absteigendArray = calloc(1, sizeof(int[ARRAYSIZE]));
    vergleichsArray = calloc(1, sizeof(int[ARRAYSIZE]));
    initArrays(randomArray, aufsteigendArray, absteigendArray, vergleichsArray);

    printf("Erster Durchlauf - Zweiter Durchlauf - Dritter Durchlauf - Durchschnitt\n");

    printf("Selection Sort:\n");
    showTime(selectionSort, randomArray, aufsteigendArray, absteigendArray);
    printf("Insertion Sort:\n");
    showTime(insertionSort, randomArray, aufsteigendArray, absteigendArray);
    printf("Shell Sort:\n");
    showTime(shellSort, randomArray, aufsteigendArray, absteigendArray);
    printf("Quick Sort:\n");
    showTime(quickSort, randomArray, aufsteigendArray, absteigendArray);
    printf("Merge Sort:\n");
    showTime(mergeSort, randomArray, aufsteigendArray, absteigendArray);
    printf("Heap Sort:\n");
    showTime(heapSort, randomArray, aufsteigendArray, absteigendArray);

    return 0;
}

void initArrays(int *randomArray, int *aufsteigendArray, int *absteigendArray, int *vergleichsarray) {
    time_t t;
    srand((unsigned) time(&t));
    aufsteigendArray[0] = 0;
    vergleichsarray[0] = 0;
    absteigendArray[0] = 0;
    for(int i = 1 ; i < ARRAYSIZE ; i++) {
        randomArray[i] = (rand() % ARRAYSIZE) + 1;
        aufsteigendArray[i] = i;
        vergleichsarray[i] = i;
        absteigendArray[i] = ARRAYSIZE - i;
    }
}

void printArray(int *array) {
    for(int i = 0; i < ARRAYSIZE; i++) {
        printf("%i, ", array[i]);
    }
    printf("\n");
}

int* testTime(void (*sortMethod)(int*), int *array) {
    int *localArray = calloc(1, sizeof(int[ARRAYSIZE]));
    int time_begin, time_end, tr1, tr2, tr3, trd;
    int *result = calloc(1, sizeof(int[4]));
    memcpy(localArray, array, sizeof(int[ARRAYSIZE]));
    sortMethod(localArray);

    memcpy(localArray, array, sizeof(int[ARRAYSIZE]));
    time_begin = clock();
    sortMethod(localArray);
    time_end = clock();
    SHOW_ARRAYS ? printArray(localArray) : 0;
    tr1 = time_end - time_begin;
    result[0] = tr1;

    memcpy(localArray, array, sizeof(int[ARRAYSIZE]));
    time_begin = clock();
    sortMethod(localArray);
    time_end = clock();
    SHOW_ARRAYS ? printArray(localArray) : 0;
    tr2 = time_end - time_begin;
    result[1] = tr2;

    memcpy(localArray, array, sizeof(int[ARRAYSIZE]));
    time_begin = clock();
    sortMethod(localArray);
    time_end = clock();
    SHOW_ARRAYS ? printArray(localArray) : 0;
    tr3 = time_end - time_begin;
    result[2] = tr3;

    trd = (tr1 + tr2 + tr3) / 3;
    result[3] = trd;

    free(localArray);
    return result;
}

void showTime(void (*sortMethod)(int*), int *randomArray, int *aufsteigendArray, int *absteigendArray){
    int *result;
    printf("Zufall:\n");
    result = testTime(sortMethod, randomArray);
    printf("%i - %i - %i - %i\n", result[0], result[1], result[2], result[3]);
    free(result);
    printf("Aufst.:\n");
    result = testTime(sortMethod, aufsteigendArray);
    printf("%i - %i - %i - %i\n", result[0], result[1], result[2], result[3]);
    free(result);
    printf("Abste.:\n");
    result = testTime(sortMethod, absteigendArray);
    printf("%i - %i - %i - %i\n\n", result[0], result[1], result[2], result[3]);
    free(result);
}

int equalArray(int *array1, int *array2) {
    for (int i = 0; i < ARRAYSIZE; i++) {
        if(array1[i] == array2[i]) {
           return 0;
        }
    }
    return 1;
}