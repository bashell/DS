#include <stdio.h>
#include <stdlib.h>

void insertSort(int a[], int len)
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

int main(int argc, char *argv[])
{
    int i;
    int test[10] = {1, 3, 2, 9, 10, 8, 4, 5, 7, 6};
    insertSort(test, 10);
    for(i = 0; i < 10; i++)
        printf("%d ", test[i]);
    printf("\n");

    exit(EXIT_SUCCESS);
}
