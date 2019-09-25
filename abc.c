#include<stdio.h>
#include<string.h>

int binSearchName(int low, int high, int target, int *arr) {
    int mid = (int)((low + high) / 2);
    printf("%d, %d\n", low, high);
    if (arr[mid] == target ) return mid;
    else if (low == high) return low + 1;
    else if (arr[mid] < target) return binSearchName(mid, high, target, arr);
    else return binSearchName(low, mid - 1, target, arr);
}

void main() {
    int arr[12] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23}; // 12 ELEMENTS
//                 0  1  2  3  4  5   6   7   8   9   10  11
    int b[4] = {-1, 6, 20, 25};
    int i = 3;
    printf("%d, pos of %d is %d\n", i, b[i], binSearchName(0, 11, b[i], arr));

    // for (i = 0; i < 3; i++) {
    //     printf("%d, pos of %d is %d\n", i, b[i], binSearchName(0, 6, b[i], arr));
    // }
}