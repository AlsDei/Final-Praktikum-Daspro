#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int num;
    int x;
    int y;
} array;

int comp(const void *a, const void *b) {
    return ((array *)a)->num - ((array *)b)->num;
}
int binarySearch(array arr[], int low, int high, int x)
{
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid].num == x)
            return arr[mid].num;

        if (arr[mid].num < x)
            low = mid + 1;

        else
            high = mid - 1;
    }

    return -1;
}

int main()
{
    int x, y, num, key;

    scanf("%d %d", &x, &y);

    array arr[x * y];

    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            scanf("%d", &num);
            arr[i * y + j].num = num;
            arr[i * y + j].x = i;
            arr[i * y + j].y = j;
        }
    }

    scanf("%d", &key);

    qsort(arr, (x*y), sizeof(arr[0]), comp);

    int result = binarySearch(arr, 0, (x * y) - 1, key);
    int found = 1;

    for(int i = 0; i < x*y; i++){
        if(arr[i].num == result){
            printf("Element %d found at position: (%lld, %lld).", key, arr[i].x + 1, arr[i].y + 1);
            found = 1;
            break;
        }
    }

    if(!found){
        printf("Element %d not found.", key);
    }

    return 0;
}
