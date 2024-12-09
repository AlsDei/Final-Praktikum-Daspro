#include <stdio.h>
#include <string.h>
#include <math.h>
#define MAX_SIZE 25

void BintoChar(char *binary, char *str)
{
    int ch = 0;
    for (int i = 0; i < 8; i++)
    {
        if (*(binary + i) == '1')
        {
            ch += pow(2, (7-i));
        }
    }
    *str = (char)ch;
}

void check(char *key, char *str, int *found)
{
    int key_len = strlen(key);
    int str_len = strlen(str);

    for (int i = 0; i <= str_len - key_len; i++)
    {
        int sama = 1;
        for (int j = 0; j < key_len; j++)
        {
            if (*(key + j) != *(str + i + j))
            {
                sama = 0;
                break;
            }
        }
        if (sama)
        {
            *found = 1;
            return;
        }
    }
    *found = 0;
}

int main()
{
    int found = 0, index = 0;
    char bin[5 * 5 * 9];
    char str[MAX_SIZE + 1], key[6];

    scanf("%s", key);

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            scanf("%s", (bin + (i * 5 + j) * 9));
        }
    }

    // check from letf to right
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            BintoChar((bin + (i * 5 + j) * 9), (str + index));
            index++;
        }
    }

    check(key, str, &found);

    // check from up to downn
    if (!found)
    {
        for (int j = 0; j < 5; j++)
        {
            for (int i = 0; i < 5; i++)
            {
                BintoChar((bin + (i * 5 + j) * 9), (str + index));
                index++;
            }
        }
    }

    check(key, str, &found);

    if (found)
    {
        printf("%s found\n", key);
    }
    else
    {
        printf("Failed to find the specified word: %s\n", key);
    }
}
