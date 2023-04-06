#include <stdio.h>
#include <time.h>
#include "headers/ds.h"

clock_t start, end;

/*SELECTION SORT
time complexity - worst, avg, best = O(n²))
space complexity - worst, avg, best = O(1)*/

void selectionSort(int arr[], int n){
    int i, j;
    for(i = 0; i < n-1; i++){
        for(j = i+1; j < n; j++){
            if(arr[i] > arr[j]){
                swap(&arr[i], &arr[j]);
            }
        }
    }
}

int main(){
    int size = 50000;
    int* arr = generateRandomArray(size);

    start = clock();

        selectionSort(arr, size);

    end = clock();

        printTime(start,end);
        checkIfSorted(arr,size);

    free(arr);
    return 0;
}

/*  
gcc selection-sort.c headers/ds.c -ansi -pedantic -Wall -o selection-sort && ./selection-sort  
*/
