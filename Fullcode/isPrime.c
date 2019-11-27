#include <stdio.h>
#include <math.h>

int isPrime(int n);

int main(){
/*  int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    if (isPrime(n) == 1){
        printf("%d is a prime number.", n);
    } else printf("%d is not a prime number.", n);
    return 0;
*/
    int x;
    printf("Enter a number: ");
    scanf("%d", &x);
    for (int i = 2; i <= x; i++){
        if (isPrime(i) == 1){
            printf("%5d", i);
        } else continue;
    }
    return 0;
}

int isPrime(int n){
    for(int i = 2; i <= sqrt(n); i++){
        if (n % i == 0){
            return 0;
        }
    }
    return 1;
}