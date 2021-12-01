cmake_minimum_required(VERSION 3.17)
project(audprakt3 C)

set(CMAKE_C_STANDARD 11)
MATH(EXPR stack_size "16 * 1024 * 1024") # 16 Mb
set(CMAKE_EXE_LINKER_FLAGS "-Wl,--stack,${stack_size}")

add_executable(audprakt3 main.c selection.c sort.h main.h shell.c heap.c quick.c merge.c insertion.c)