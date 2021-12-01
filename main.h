//
// Created by marce on 20.11.2021.
//

#ifndef AUDPRAKT3_MAIN_H
#define AUDPRAKT3_MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "sort.h"

void initArrays(int *randomArray, int *aufsteigendArray, int *absteigendArray, int *vergleichsarray);
int* testTime(void (*sortMethod)(int*), int *array);
void showTime(void (*sortMethod)(int*), int *randomArray, int *aufsteigendArray, int *absteigendArray);
/**
 *
 * @param array1
 * @param array2
 * @return 1 wenn Arrays gleich sind, sonst 0
 */
int equalArray(int *array1, int *array2);

#endif //AUDPRAKT3_MAIN_H
