#include <stdio.h>
#include <stdlib.h>

void insertSort(int *a, int len)
{
    int i, j;
    int temp;

    for(i = 1; i < len; i++)
    {
        temp = a[i];
        for(j = i - 1; j >= 0 && a[j] > temp; j--)
            a[j + 1] = a[j];    // 所有大于temp的元素都后移1位
        a[j + 1] = temp;    // 在第一个不大于temp的元素后面插入temp
    }
}

static void swap(int *left, int *right)
{
    *left += *right;
    *right = *left - *right;
    *left = *left - *right;
}

int partion(int *a, int len)
{
    int low, high, key;

    low = 0;
    high = len - 1;
    key = a[0];
    while(low < high)
    {
        while(low < high && a[high] >= key)    // 左 < key <= 右
            high--;
        if(low < high)
            swap(&a[high], &a[low]);
        while(low < high && a[low] < key)
            low++;
        if(low < high)
            swap(&a[high], &a[low]);
    }
    return low;
}

void quickSort(int *a, int len)
{
    int part;
    if(len <= 5)
        insertSort(a, len);
    else
    {
        part = partion(a, len);
        quickSort(a, part);
        quickSort(&a[part + 1], len - (part + 1));
    }
}

int main(int argc, char *argv[])
{
    int i;
    int test[10] = {1, 3, 2, 9, 10, 8, 4, 5, 6, 7};
    quickSort(test, 10);
    for(i = 0; i < 10; i++)
        printf("%d ", test[i]);
    printf("\n");

    exit(EXIT_SUCCESS);
}
