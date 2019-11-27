#include <stdio.h>

int sumCube(int n);
void submultiples(int n);
void firstSquare(int n);

int main(){
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    printf("The sum of the cube of integers from 1 to %d is: %d\n", n, sumCube(n));
    printf("\nThe list of all submultiples of the integer %d is:\n", n);
    submultiples(n);
    printf("\nThe list of %d first square number:\n", n);
    firstSquare(n);
    return 0;
}

int sumCube(int n){
    int sum = 0;
    for (int i = 1; i <= n; i++){
        sum += i * i * i;
    }
    return sum;
}

void submultiples(int n){
    for (int i = 1; i <= n; i++){
        if (n % i == 0) printf("%5d", i);
    }
}

void firstSquare(int n){
    for (int i = 1; i <= n; i++){
        printf("%5d", i*i);
    }
}