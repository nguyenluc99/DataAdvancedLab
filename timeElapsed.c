#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<unistd.h>
#define RAND_MAX 0x100
void main()
{
    int a;
    time_t  start, end;
    start = time(NULL);
    // printf("%d\n", start);
    srand(time(0)); //use current time as seed for random generator
    // RAND_MAX = 10;
    int ranNum = rand();
    printf("Random value on [0,%d]: %d\n", RAND_MAX, ranNum);
    sleep(3);
    end = time(NULL);
    // printf("%d\n", end);
    printf("time is  %d",  end-start);
    
}