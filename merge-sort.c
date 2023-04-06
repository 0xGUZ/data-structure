#include <stdio.h>
#include <time.h>
#include "headers/ds.h"

clock_t start, end;

/*MERGE SORT
time complexity - worst, avg, best = O(n*log(n))
space complexity - worst, avg, best = O(n)*/

void mergeSort(int arr[], int size){

}

int main(){
    int size = 1000;
    int* arr = generateRandomArray(size);

    start = clock();

        mergeSort(arr, size);

    end = clock();

        printTime(start,end);
        checkIfSorted(arr, size);

    free(arr);
    return 0;
}

/*  gcc merge-sort.c headers/ds.c -ansi -pedantic -Wall -o merge-sort && ./merge-sort   */