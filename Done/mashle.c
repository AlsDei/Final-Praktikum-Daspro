#include <stdio.h>
#include <string.h>
int main()
{
    char sen[101];
    int n, i = 0, beda, k = 0, totallen = 0, selisih;

    scanf("%d %s", &n, &sen);

    int len = strlen(sen);
    if (len % n != 0)
    {
        beda = (len + n - 1) / n;
        selisih = (beda * n) - len;
    }
    else
        beda = len / n;

    int tempb = beda;
    char set[101][101];

    for (int i = 0; i < n; i++)
    {
        if (i == n - selisih)
        {
            tempb--;
        }
        for (int j = 0; j < tempb; j++)
        {
            set[i][j] = sen[k];
            k++;
            totallen++;
            if (totallen == len)
            {
                break;
            }
        }
    }

    int lenss = 0;

    for (int i = 0; i < beda; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (set[j][i] == '_')
            {
                printf(" ");
            }
            else
                printf("%c", set[j][i]);
            lenss++;
            if (lenss == len)
            {
                break;
            }
        }
    }
}
