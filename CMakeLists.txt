cmake_minimum_required(VERSION 3.17)
project(audprakt3 C)

set(CMAKE_C_STANDARD 11)

add_executable(audprakt3 main.c selection.c sort.h main.h shell.c heap.c quick.c merge.c insertion.c)