#ifndef DS_H_
#define DS_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//utils
int* generateRandomArray(int size);

void swap(int* a, int*b);

int checkIfSorted(int* arr, int size);

void printArray(int arr[], int n);

void printTime(clock_t start, clock_t end);

//sorting algorithms
void selectionSort(int arr[], int n);

#endif