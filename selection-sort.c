#include <stdio.h>
#include <time.h>
#include "headers/ds.h"

clock_t start, end;

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

    return 0;
}

