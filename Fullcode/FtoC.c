#include <stdio.h>

float celcius(int f);

int main(){
    printf("__________________\n");
    printf("| F |         C   |\n");
    printf("_________________\n");
    for (int i = 0; i <= 20; i++){
        printf("%3d%12.2f\n", i, celcius(i));
    }
    return 0;
}

float celcius(int f){
    return 5 / 9 * (f - 32);
}