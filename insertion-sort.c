#include <stdio.h>
#include <time.h>
#include "headers/ds.h"

clock_t start, end;

/*INSERTION SORT
time complexity - worst, avg, best = O(n²)
space complexity - worst, avg, best = O(n) + O(1) auxiliar*/

void insertionSort(int arr[], int n){
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

int main(){
    int size = 50000;

    /*avg*/
    int* arr = generateRandomArray(size);

    start = clock();

        insertionSort(arr, size);

    end = clock();

        printf("AVERAGE arr ---\n");
        printTime(start,end);
        checkIfSorted(arr,size);

    free(arr);
    return 0;
}

/*  
gcc insertion-sort.c headers/ds.c -ansi -pedantic -Wall -o insertion-sort && ./insertion-sort  
*/