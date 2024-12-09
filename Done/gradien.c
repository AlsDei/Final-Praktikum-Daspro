#include <stdio.h>
#include <string.h>
int main()
{
    double x1, x2, y1, y2;

    scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);

    double grad = (y1 - y2)/(x1 - x2);
    double c = y1 - (grad*x1);

    if(x1 == x2){
        printf("-_-");
    }else printf("%.2lf %.2lf", grad, c);
}
