#include <stdio.h>
#include <time.h>
#include "headers/ds.h"

clock_t start, end;

/*TEMPLATE SORT
time complexity - worst, avg, best = O( )
space complexity - worst, avg, best = O( )*/

void renameThis(int arr[], int n){
    int i, j;

}

int main(){
    int size = 1000;
    int* arr = generateRandomArray(size);

    start = clock();

        renameThis(arr, size);

    end = clock();

        printTime(start,end);
        checkIfSorted(arr,size);

    free(arr);
    return 0;
}

/*  
gcc renameThis-sort.c headers/ds.c -ansi -pedantic -Wall -o renameThis-sort && ./renameThis-sort  
*/