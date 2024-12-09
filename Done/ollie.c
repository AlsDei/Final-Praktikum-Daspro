#include <stdio.h>
#include <string.h>
int main()
{
    long long n, total = 0;
    char name[1001];

    scanf("%s %lld", &name, &n);

    if (strcmp(name, "Ellie") == 0)
    {
        for (long long i = 0; i <= n; i++)
        {
            if (i % 2 == 0)
            {
                total += i;
            }
        }
        printf("%lld", total);
    }
    else if (strcmp(name, "Oddie") == 0)
    {

        for (long long i = 0; i <= n; i++)
        {
            if (i % 2 != 0)
            {
                total += i;
            }
        }
        printf("%lld", total);
    }
    else{
        printf("Who is that?");
    }



}