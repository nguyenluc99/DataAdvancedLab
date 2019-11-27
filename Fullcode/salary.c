#include <stdio.h>

int wage(int hour);

int main(){
    int n;
    printf("Enter the time the worker worked in a week (hour): ");
    scanf("%d", &n);
    if (n < 10 || n > 65) {
        printf("Unvalid data.");
    } else {
        printf("The worker's salary is: %d VND", wage(n));
    }
    return 0;
}

int wage(int hour){
    int wage;
    if(hour <= 40) {
        wage = 15000 * hour;
    } else wage = 15000 * 40 + 1.5 * 15000 * (hour - 40);
    return wage;
}