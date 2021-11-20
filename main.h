//
// Created by marce on 20.11.2021.
//

#ifndef AUDPRAKT3_MAIN_H
#define AUDPRAKT3_MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define ARRAYSIZE 200000

void initArrays(int *randomArray, int *aufsteigendArray, int *absteigendArray);
void printArray(int *array);
int* testTime(void (*sortMethod)(int*), int *array);
void showTime(void (*sortMethod)(int*), int *randomArray, int *aufsteigendArray, int *absteigendArray);

#endif //AUDPRAKT3_MAIN_H
