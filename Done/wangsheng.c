#include <stdio.h>
#include <string.h>

/*
    furina - 3
    hutao - 2
    lyney - 1

    istirahat - 7
    beraksi - 6
*/

void printno(int b, int c)
{
    char lastau[17], nowau[17];
    switch (b)
    {
    case 3:
        strcpy(lastau, "furina");
        break;
    case 2:
        strcpy(lastau, "hutao");
        break;
    case 1:
        strcpy(lastau, "lyney");
        break;
    }

    switch (c)
    {
    case 3:
        strcpy(nowau, "furina");
        break;
    case 2:
        strcpy(nowau, "hutao");
        break;
    case 1:
        strcpy(nowau, "lyney");
        break;
    }

    printf("Oceanid Minion tidak nurut karena wewenang %s lebih rendah dari %s.\n", lastau, nowau);
}

void printtext(int a, int b, int c)
{
    char command[17], name[17];
    int nolast = a, nonow = b;
    if (c == 3)
    {
        printno(nolast, nonow);
    }
    else
    {

        switch (nonow)
        {
        case 3:
            strcpy(name, "furina");
            break;
        case 2:
            strcpy(name, "hutao");
            break;
        case 1:
            strcpy(name, "lyney");
            break;
        }

        switch (nolast)
        {
        case 7:
            strcpy(command, "beraksi");
            break;
        case 6:
            strcpy(command, "istirahat");
            break;
        }

        if (c == 1)
        {
            printf("Oceanid Minion sudah diperintah %s oleh %s.\n", command, name);
        }
        else if (c == 2)
        {
            printf("Oceanid Minion %s sesuai keinginan %s.\n", command, name);
        }
    }
}

int main()
{
    int n, nowauth = 0, lastauth = 0, lastcom = 0, nowcom = 0, samecom = 0, highest = 0;
    char com[17], name[17];

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%s %s", name, com);
        if (strcmp(name, "furina") == 0)
        {
            nowauth = 3;
        }
        else if (strcmp(name, "hutao") == 0)
        {
            nowauth = 2;
        }
        else if (strcmp(name, "lyney") == 0)
        {
            nowauth = 1;
        }

        if (strcmp(com, "istirahat") == 0 && lastauth == 0)
        {
            printf("Oceanid Minion marah karena belum diperintah apa-apa, tetapi sudah disuruh istirahat!\n");
            break;
        }

        if (strcmp(com, "beraksi") == 0)
        {
            nowcom = 7;
        }
        else if (strcmp(com, "istirahat") == 0)
        {
            nowcom = 6;
        }
        if (nowauth > highest)
        {
            highest = nowauth;
        }

        //! IF BERAKSI
        if (nowcom == 7)
        {
            if (nowauth >= highest)
            {
                if (nowcom == lastcom)
                {

                    printtext(nowcom, lastauth, 1);
                    lastcom = nowcom;
                    lastauth = lastauth;
                }
                else
                {
                    printtext(nowcom, nowauth, 2);
                    lastcom = nowcom;
                    lastauth = nowauth;
                }
            }
            else if (nowauth < highest)
            {

                printtext(nowauth, highest, 3);
                lastcom = lastcom;
                lastauth = lastauth;
            }
        }
        //! if ISTIRAHAT
        else if (nowcom == 6)
        {
            if (nowauth >= highest)
            {
                if (nowcom == lastcom)
                {

                    printtext(nowcom, lastauth, 1);
                    lastcom = nowcom;
                    lastauth = lastauth;
                }
                else
                {
                    printtext(nowcom, nowauth, 2);
                    lastcom = nowcom;
                    lastauth = nowauth;
                }
            }
            else if (nowauth < highest)
            {

                printtext(nowauth, highest, 3);
                lastcom = lastcom;
                lastauth = lastauth;
            }
        }
    }
}
