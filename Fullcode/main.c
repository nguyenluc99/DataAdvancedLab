#include <stdio.h>

double kineticEnergy(double m, double v);

int main(){
    double m, v;
    printf("Enter the mass (kg): ");
    scanf("%lf", &m);
    printf("Enter the velocity (m/s): ");
    scanf("%lf", &v);
    printf("The kinetic energy of the element is: %.2lf (J)", kineticEnergy(m, v));
    return 0;
}

double kineticEnergy(double m, double v){
    return (m * v * v / 2);
}