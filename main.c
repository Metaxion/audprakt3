#include "main.h"
#include "sort.h"

int main() {

    int *randomArray = calloc(1, sizeof(int[ARRAYSIZE]));
    int *aufsteigendArray = calloc(1, sizeof(int[ARRAYSIZE]));;
    int *absteigendArray = calloc(1, sizeof(int[ARRAYSIZE]));;
    initArrays(randomArray, aufsteigendArray, absteigendArray);

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

void initArrays(int *randomArray, int *aufsteigendArray, int *absteigendArray) {
    time_t t;
    srand((unsigned) time(&t));
    for(int i = 0 ; i < ARRAYSIZE ; i++) {
        randomArray[i] = (rand() % ARRAYSIZE) + 1;
        aufsteigendArray[i] = i + 1;
        absteigendArray[i] = ARRAYSIZE - i;
    }
}

void printArray(int *array) {
    for(int i = 0; i < ARRAYSIZE ; i++) {
        printf("%i, ", array[i]);
    }
}

int* testTime(void (*sortMethod)(int*), int *array) {
    int *localArray = calloc(1, sizeof(int[ARRAYSIZE]));
    int time_begin, time_end, tr1, tr2, tr3, trd;
    int *result = calloc(1, sizeof(int[4]));

    memcpy(localArray, array, sizeof(int[ARRAYSIZE]));
    time_begin = clock();
    sortMethod(localArray);
    time_end = clock();
    tr1 = time_end - time_begin;
    result[0] = tr1;

    memcpy(localArray, array, sizeof(int[ARRAYSIZE]));
    time_begin = clock();
    sortMethod(localArray);
    time_end = clock();
    tr2 = time_end - time_begin;
    result[1] = tr2;

    memcpy(localArray, array, sizeof(int[ARRAYSIZE]));
    time_begin = clock();
    sortMethod(localArray);
    time_end = clock();
    tr3 = time_end - time_begin;
    result[2] = tr3;

    trd = (tr1 + tr2 + tr3) / 3;
    result[3] = trd;

    free(localArray);
    return result;
}

void showTime(void (*sortMethod)(int*), int *randomArray, int *aufsteigendArray, int *absteigendArray){
    int *result;
    printf("Zufall:");
    result = testTime(sortMethod, randomArray);
    printf("%i - %i - %i - %i\n", result[0], result[1], result[2], result[3]);
    printf("Aufst.:");
    result = testTime(sortMethod, aufsteigendArray);
    printf("%i - %i - %i - %i\n", result[0], result[1], result[2], result[3]);
    printf("Abste.:");
    result = testTime(sortMethod, absteigendArray);
    printf("%i - %i - %i - %i\n\n", result[0], result[1], result[2], result[3]);
}