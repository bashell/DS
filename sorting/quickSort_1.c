#include <stdio.h>
#include <stdlib.h>

void quickSort(int *arr, int left, int right)
{
    if(left < right)
    {
        int i = left, j = right, target = arr[left];
        while(i < j)
        {
            while(i < j && arr[j] > target)
                j--;
            if(i < j)
                arr[i++] = arr[j];
            while(i < j && arr[i] < target)
                i++;
            if(i < j)
                arr[j] = arr[i];
        }
        arr[i] = target;
        quickSort(arr, left, i - 1);
        quickSort(arr, i + 1, right);
    }
}

int main(int argc, char *argv[])
{
    int i;
    int test[] = {1, 3, 2, 9, 10, 8, 4, 5, 6, 7};
    quickSort(test, 0, 9);
    for(i = 0; i < 10; i++)
        printf("%d ", test[i]);
    printf("\n");

    exit(EXIT_SUCCESS);
}
