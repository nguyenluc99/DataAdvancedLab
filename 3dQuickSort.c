#include<stdio.h> // memcpy // int qsort(a, n, sizeof(int), intCompare)
#include<time.h>
#include<stdlib.h>

void quickSort(int *arr, long low, long high){
    int pivot = arr[high];
    long i = low, j = high - 1;
    long firstE = low, lastE = high;
    do {
        if (arr[i] > pivot) swap(&arr[i], &arr[j]);
        i ++;
        if (arr[j] < pivot) swap(&arr[i], &arr[j]);
        j --;
    } while (i != j);
    
    if (low >= high) return;
}

void swap(int *a, int *b) {
    int temp;
    if (*a != *b){
        temp = *a;
        *a = *b;
        *b = temp;
    }
}



void main(){
    int arr[9] = {2, 5, 1, 7, 8, 4, 3, 9, 6};
    long len = 9;
    long i;
    time_t start, end;
    start = time(NULL);

    quickSort(arr, 0, 8);

    end = time(NULL);
    printf("time elapsed :  %.2f", end - start);
    for (i = 0; i < len; i++){
        printf("%d - ", arr[i]);
    }
    printf("\n");

}
