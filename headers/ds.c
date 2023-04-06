#include "ds.h"

int* generateRandomArray(int size) {
    int* arr = malloc(size * sizeof(int));
    int i;
    for (i = 0; i < size; i++) {
        arr[i] = rand() % (2 * size + 1) - size;
    }
    return arr;
}

void swap(int* a, int* b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int checkIfSorted(int* arr, int size){
    int i;
    for(i=0; i<size-1; i++){
        if (arr[i] > arr[i+1]){
            printf("\nNOT SORTED --- X\n");
            printf("arr[%d] = %d, arr[%d] = %d\n\n", i, arr[i], i+1, arr[i+1]);
            return 0;
        }
    }
    printf("\nSORTED --- V\n\n");
    return 1;
}

void printArray(int arr[], int n){
    int i;
    for(i = 0; i < n; i++){
        printf("i=%d: %d\n", i, arr[i]);
    }
}

void printTime(clock_t start, clock_t end){
    printf("\ntime: %fms\n",((double) (end - start)) / CLOCKS_PER_SEC * 1000.0);
}