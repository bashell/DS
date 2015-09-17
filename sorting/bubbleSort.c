#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int a[], int len)
{
    int i, j;
    int temp;

    // 每轮都将本轮处理的最大元素放到最终的位置.
    for(i = 0; i < len - 1; i++)
        for(j = 0; j < len - 1 - i; j++)
            if(a[j + 1] < a[j])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
}

int main(int argc, char *argv[])
{
    int i;
    int test[10] = {1, 3, 2, 9, 10, 8, 4, 5, 6, 7};
    bubbleSort(test, 10);
    for(i = 0; i < 10; i++)
        printf("%d ", test[i]);
    printf("\n");

    exit(EXIT_SUCCESS);
}
