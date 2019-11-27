#include <stdio.h>

double getJudgeData();
void calcScore();
double findHighest(double n1, double n2, double n3, double n4, double n5);
double findLowest(double n1, double n2, double n3, double n4, double n5);
int main(){
    double n1, n2, n3, n4, n5;
    n1 = getJudgeData();
    n2 = getJudgeData();
    n3 = getJudgeData();
    n4 = getJudgeData();
    n5 = getJudgeData();
    findHighest(n1, n2, n3, n4, n5);
    findLowest(n1, n2, n3, n4, n5);
    calcScore(n1, n2, n3, n4, n5);
    return 0;
}

double getJudgeData(){
    double n;
    printf("Enter a score: ");
    scanf("%lf", &n);
    return n;
}

double findHighest(double n1, double n2, double n3, double n4, double n5){
    double max = n1;
    if (n2 >= max) max = n2;
    if (n3 >= max) max = n3;
    if (n4 >= max) max = n4;
    if (n5 >= max) max = n5;
    return max;
}
double findLowest(double n1, double n2, double n3, double n4, double n5){
    double min = n1;
    if (n2 <= min) min = n2;
    if (n3 <= min) min = n3;
    if (n4 <= min) min = n4;
    if (n5 <= min) min = n5;
    return min;
}

void calcScore(double n1, double n2, double n3, double n4, double n5){
    double avg = (n1 + n2 + n3 + n4 + n5 - findHighest(n1, n2, n3, n4, n5) - findLowest(n1, n2, n3, n4, n5))/3;
    printf("The score of this contestant is: %lf", &avg);
}