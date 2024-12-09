#include <stdio.h>
#include <math.h>

long double pi = 3.14159265358979323846;

int main()
{
    long double V;
    scanf("%Lf", &V);

    long double r = cbrt((V / (2.0 * pi)));
    long double t1 = 2 * r;
    long double t2 = V/ (pi *r * r);

    if((t2 - t1) < 0.00000000001){
        printf("Luas permukaan: %.2Lf\n", 2 * pi * r * (r+t2));
    }
}

