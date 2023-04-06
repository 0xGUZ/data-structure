#include "ds.h"

/*util*/
int* generateRandomArray(int size) {
    int* arr = malloc(size * sizeof(int));
    int i;
    for (i = 0; i < size; i++) {
        arr[i] = rand() % (2 * size + 1) - size;
    }
    return arr;
}

int* generateSortedArray(int size) {
    int* arr = malloc(size * sizeof(int));
    int i;
    for (i = 0; i < size; i++){
        arr[i] = i;
    }
    return arr;
}

int* generateInvertedSortedArray(int size) {
    int* arr = malloc(size * sizeof(int));
    int i;
    for (i = 0; i < size; i++){
        arr[i] = size-i-1;
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

/*sorting algorithms*/
void dsSelectionSort(int arr[], int n){
    int i, j;
    for(i = 0; i < n-1; i++){
        for(j = i+1; j < n; j++){
            if(arr[i] > arr[j]){
                swap(&arr[i], &arr[j]);
            }
        }
    }
}

void dsBubbleSort(int arr[], int n){
    int i;

    if (n < 1) return;
    for(i=0; i<n; i++){
        if(arr[i] > arr[i+1]){
            swap(&arr[i],&arr[i+1]);
        }
    }
    dsBubbleSort(arr, n-1);
}

void dsInsertionSort(int arr[], int n){
    int i, j, k;
    for(i=0; i<n; i++){
        k = arr[i];
        j = i - 1;
        while(j >= 0 && arr[j] > k){
            arr[j+1] = arr[j];
            --j;
            arr[j+1] = k;
        }
    }
}