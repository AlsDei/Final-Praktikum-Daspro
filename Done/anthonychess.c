#include <stdio.h>
#include <string.h>

int map[8][8] = {0};
void chesstoarr(int *x, int *y, char *str)
{
    *x = (int)str[0] - 'a';
    *y = (int)str[1] - '1';
}

int check = 0;

void chessChecker(char *whiteking, char *whitequ, char *blackking, char *blackqu, char *key)
{
    int whiki, whikj, whiqi, whiqj, blaki, blakj, blaqi, blaqj;

    chesstoarr(&whiki, &whikj, whiteking);
    map[whiki][whikj] = 69;
    chesstoarr(&whiqi, &whiqj, whitequ);
    map[whiqi][whiqj] = 96;
    chesstoarr(&blaki, &blakj, blackking);
    map[blaki][blakj] = 420;
    chesstoarr(&blaqi, &blaqj, blackqu);
    map[blaqi][blaqj] = 240;

    int count = 0;

    if (*key == 'b')
    {
        for (int i = blaqj; i < 8; i++)
        {

            if (i != blaqj)
            {
                count += map[blaqi][i];
                if (count == 69)
                {
                    check = 1;
                    break;
                }
            }
        }
        count = 0;
        for (int i = blaqi; i >= 0; i--)
        {
            if (i != blaqi)
            {
                count += map[i][blaqj];
                if (count == 69)
                {
                    check = 1;
                    break;
                }
            }
        }
        count = 0;
        for (int i = blaqj; i >= 0; i--)
        {
            if (i != blaqj)
            {
                count += map[blaqi][i];
                if (count == 69)
                {
                    check = 1;
                    break;
                }
            }
            count = 0;
            for (int i = blaqi; i < 8; i++)
            {
                if (i != blaqi)
                {
                    count += map[i][blaqj];
                    if (count == 69)
                    {
                        check = 1;
                        break;
                    }
                }
            }
            count = 0;
            int k = blaqj;
            for (int i = blaqi; i < 8; i++)
            {
                if (k < 8)
                {
                    if (i != blaqi && k != blaqj)
                    {
                        count += map[i][k];
                        if (count == 69)
                        {
                            check = 1;
                            break;
                        }
                    }
                    k++;
                }
            }
            count = 0;
            k = blaqj;
            for (int i = blaqi; i < 8; i++)
            {
                if (k >= 0)
                {
                    if (i != blaqi && k != blaqj)
                    {
                        count += map[i][k];
                        if (count == 69)
                        {
                            check = 1;
                            break;
                        }
                    }
                    k--;
                }
            }
            count = 0;
            k = blaqj;
            for (int i = blaqi; i >= 0; i--)
            {
                if (k < 8)
                {
                    if (i != blaqi && k != blaqj)
                    {
                        count += map[i][k];
                        if (count == 69)
                        {
                            check = 1;
                            break;
                        }
                    }
                    k++;
                }
            }
            count = 0;
            k = blaqj;
            for (int i = blaqi; i >= 0; i--)
            {
                if (k >= 0)
                {
                    if (i != blaqi && k != blaqj)
                    {
                        count += map[i][k];
                        if (count == 69)
                        {
                            check = 1;
                            break;
                        }
                    }
                    k--;
                }
            }
        }
        if (check)
        {
            printf("Black checked White!\n");
        }
    }
    else if (*key == 'w')
    {
        count = 0;
        for (int i = whiqj; i < 8; i++)
        {

            if (i != whiqj)
            {
                count += map[whiqi][i];
                if (count == 420)
                {
                    check = 1;
                    break;
                }
            }
        }
        count = 0;
        for (int i = whiqi; i >= 0; i--)
        {
            if (i != whiqi)
            {
                count += map[i][whiqj];
                if (count == 420)
                {
                    check = 1;
                    break;
                }
            }
        }
        count = 0;
        for (int i = whiqj; i >= 0; i--)
        {
            if (i != whiqj)
            {
                count += map[whiqi][i];
                if (count == 420)
                {
                    check = 1;
                    break;
                }
            }
        }
        count = 0;
        for (int i = whiqi; i < 8; i++)
        {
            if (i != whiqi)
            {
                count += map[i][whiqj];
                if (count == 420)
                {
                    check = 1;
                    break;
                }
            }
        }
        count = 0;
        int k = whiqj;
        for (int i = whiqi; i < 8; i++)
        {
            if (k < 8)
            {
                if (i != whiqi && k != whiqj)
                {
                    count += map[i][k];
                    if (count == 420)
                    {
                        check = 1;
                        break;
                    }
                }
                k++;
            }
        }
        count = 0;
        k = whiqj;
        for (int i = whiqi; i < 8; i++)
        {
            if (k >= 0)
            {
                if (i != whiqi && k != whiqj)
                {
                    count += map[i][k];
                    if (count == 420)
                    {
                        check = 1;
                        break;
                    }
                }
                k--;
            }
        }
        count = 0;
        k = whiqj;
        for (int i = whiqi; i >= 0; i--)
        {
            if (k < 8)
            {
                if (i != whiqi && k != whiqj)
                {
                    count += map[i][k];
                    if (count == 420)
                    {
                        check = 1;
                        break;
                    }
                }
                k++;
            }
        }
        count = 0;
        k = whiqj;
        for (int i = whiqi; i >= 0; i--)
        {
            if (k >= 0)
            {
                if (i != whiqi && k != whiqj)
                {
                    count += map[i][k];
                    if (count == 420)
                    {
                        check = 1;
                        break;
                    }
                }
                k--;
            }
        }
        if (check)
        {
            printf("White checked Black!");
        }
    }

    if (!check)
    {
        printf("Game is still going!");
    }
}

int main()
{

    char wk[3], wq[3], bk[3], bq[3], x;
    scanf("%s %s ", wk, wq);
    scanf("%s %s ", bk, bq);
    scanf("%c", &x);
    chessChecker(wk, wq, bk, bq, &x);
    return 0;
}
