#include <stdio.h>
#include <string.h>
#include <math.h>
int main()
{
    long long ax, ay, az, bx, by, bz, cx, cy, cz, ra, rb, max;

    scanf("%lld %lld %lld %lld %lld %lld %lld %lld %lld %lld %lld %lld", &ax, &ay, &az, &bx, &by, &bz, &cx, &cy, &cz, &ra, &rb, &max);
    double dis_ab = sqrt(pow(bx - ax, 2) + pow(by - ay, 2) + pow(bz - az, 2));
    double dis_bc = sqrt(pow(cx - bx, 2) + pow(cy - by, 2) + pow(cz - bz, 2));
    double dis_ca = sqrt(pow(cx - ax, 2) + pow(cy - ay, 2) + pow(cz - az, 2));

    double maxA = ra * max;
    double maxB = rb * max;

    if ((maxA) >= dis_ca)
    {
        printf("NAH ID WIN, NO NEED TO STOP");
    }
    else if ((dis_ab + dis_bc) <= (ra + rb) * max)
    {
        printf("HHM BETTER TAKE ROCKET, STILL CAN WIN");
    }
    else 
    {
        printf("GIVE UP ALREADY, MINING BETTER");
    }
}
