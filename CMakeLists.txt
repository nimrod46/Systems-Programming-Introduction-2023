cmake_minimum_required(VERSION 3.24)
project(Systems_Programming_Introduction_2023 C)

set(CMAKE_C_STANDARD 99)

add_executable(Systems_Programming_Introduction_2023 practice09/exercises/CheckParen.c practice09/exercises/IsCyclic.c
        practice09/ADT/LinkedList.c practice09/ADT/LinkedList.h practice09/ADT/Stack.c practice09/ADT/TestLinkedList.c
        practice09/ADT/TestLinkedList.h practice09/ADT/TestStack.c practice09/main.c practice09/exercises/IsCyclic.h practice09/exercises/CheckParen.h)
