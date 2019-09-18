#include<stdio.h>
// #include<string.h>
#include<time.h>
#include<stdlib.h>
#include<unistd.h>
void genArray(int *arr, int len) {
    int i, temp;
    // printf("start, len is %d\n", len);
    // srand(time(0)); 
    for (i = 0; i < len; i++) {
        // printf(" %d ", rand() ); 
        temp = rand();
        // printf("%d - %d \n", i, temp);
        arr[i] = temp % 1000000;
    }
    // printf("finished\n");
}
void printArray(int *arr, int len){
    int i;
    for (i = 0; i < len; i++){
        printf("%d - ", arr[i]);
    }
    printf("\n");
}
void quickSort(int *arr, int low, int high){
    printf("%d\n", arr[1]);
    int pivot = arr[low];
    int i, temp, currentIndex = low;
    if (low >= high) return ;
    for (i = low + 1; i <= high; i++){
        if (pivot > arr[i]) {
            temp = arr[i];
            arr[i] = pivot;
            arr[currentIndex] = temp;
            // currentIndex = i;
            currentIndex ++;
        } else {

        }
    }
    quickSort(arr, low, currentIndex - 1);
    quickSort(arr, currentIndex + 1, high);
}

///     {3, 9, 2, 8, 1, 7, 4, 6, 5};
// 

void main(){
    int arr[10];// = {1, 9, 2, 5, 3, 7, 4, 8, 6};
    int i, len = 10;
    char ch;
    time_t  start, end;
    start = time(NULL);
    
    genArray(arr, len);
    quickSort(arr, 0, len - 1);
    end = time(NULL); 
    printf("end : %d,\nstart : %d,\n", end, start);
    printf("time elapsed : %d\n", end - start);
    for (i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
}