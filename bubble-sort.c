#include <stdio.h>
#include <time.h>
#include "headers/ds.h"

clock_t start, end;

/*BUBBLE SORT
time complexity - worst, avg, best = O(n²)
space complexity - worst, avg, best = O(1)*/

void bubbleSort(int arr[], int n){
    int i;

    if (n < 1) return;
    for(i=0; i<n; i++){
        if(arr[i] > arr[i+1]){
            swap(&arr[i],&arr[i+1]);
        }
    }
    bubbleSort(arr, n-1);
}

int main(){
    int size = 50000;
    int* arr = generateRandomArray(size);

    start = clock();

        bubbleSort(arr, size);

    end = clock();

        printTime(start,end);
        checkIfSorted(arr,size);

    free(arr);
    return 0;
}

/*  
gcc bubble-sort.c headers/ds.c -ansi -pedantic -Wall -o bubble-sort && ./bubble-sort  
*/