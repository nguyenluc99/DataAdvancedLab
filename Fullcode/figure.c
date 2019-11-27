#include <stdio.h>
#include <math.h>
void checkFigure(int n);

int main(){
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    checkFigure(n);
    return 0;
}

void checkFigure(int n){
    int k, even = 0, odd = 0;
    do {
        k = (n % 10);
        n = (int) n / 10;
        if (k % 2 == 0) even++;
        else  odd++;
    } while (n >= 1 );
    printf("The number of even figure: %d\n", even);
    printf("The number of odd figure: %d", odd);
}