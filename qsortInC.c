#include<stdlib.h>
#include<stdio.h>
#include<time.h>
// #include<string.h>

int search(void* buf, int size, int l, int r, void* item, int (*compare)(void const*, void const*)) {
    if (r < l) return -1;
    // printf("hie\n");
    int i = (int) (l + r) / 2;
    int res = compare(item, buf+size*(i));
    if (res == 0){
        return i;
    } else if(res < 0) {
        return search(buf, size, l, i-1, item, compare);
    } else return search(buf, size, i + 1, r, item, compare);
}

void genArray(int *arr, long len) {
    long i;
    // srand(time(0)); 
    for (i = 0; i < len; i++) {
        arr[i] = rand() % 100;
    }
}

int intCompare(void const* x, void const* y) {
    int m, n;
    m = *((int*)x);
    n = *((int*)y);
    if (m == n) return 0;
    else if (m > n) return 1;
    return -1;
}

void main() {
    int a[100] ; //= {1, 9, 2, 5, 3, 200, 100, 8, 6, 10};
    long i, len = 100;
    double seconds ;
    int target = 7;
    clock_t end, start = clock();

    genArray(a, len);
    qsort(a, len, sizeof(int), intCompare);
    printf("index of  %d is %d", target, search(a, sizeof(a[0]), 0, len - 1, &target, intCompare));
    printf("\n");
    for (i = 0; i < len ; i++){
        printf("%d - ", a[i]);
    }
    printf("\n");
    end = clock();
    float timeUsed = ((float)(end - start));// / CLOCKS_PER_SEC;
    printf("\nTime elapsed : %ld,  %ld,  %.5f \n", end, start, timeUsed);
}