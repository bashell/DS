#include <stdio.h>
#include <stdlib.h>

void mergeSort(int a[], int len)
{
    int *tempArray;

    tempArray = malloc(len * sizeof(int));
    if(tempArray == NULL)
    {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    mSort(a, tempArray, 0, len - 1);
}

void mSort(int a[], int tempArray[], int left, int right)
{
    int center;

    if(left < right)
    {
        center = (left + right) / 2;
        mSort(a, tempArray, left, center);
        mSort(a, tempArray, center + 1, right);
        merge(a, tempArray, left, center + 1, right);
    }
}

void merge(int a[], int tempArray[], int lpos, int rpos, int rightEnd)    // lpos: 左半部分起始点  rpos: 右半部分起始点
{
    int i, leftEnd, numElements, tempPos;

    leftEnd = rpos - 1;    // 左半部分终点
    tempPos = lpos;
    numElements = rightEnd - lpos + 1;    // 元素总数

    while(lpos <= leftEnd && rpos <= rightEnd)    // 将两个部分值小的元素加入到tempArray中
        if(a[lpos] <= a[rpos])
            tempArray[tempPos++] = a[lpos++];
        else
            tempArray[tempPos++] = a[rpos++];

    while(lpos <= leftEnd)  // 拷贝左半部分剩余元素
        tempArray[tempPos++] = a[lpos++];
    while(rpos <= rightEnd) // 拷贝右半部分剩余元素
        tempArray[tempPos++] = a[rpos++];

    // 将tempArray[]写入到a[]中
    for(i = 0; i < numElements; i++, rightEnd--)
        a[rightEnd] = tempArray[rightEnd];
}

int main(int argc, char *argv[])
{
    int i;
    int test[10] = {1, 3, 2, 9, 10, 8, 4, 5, 6, 7};
    mergeSort(test, 10);
    for(i = 0; i < 10; i++)
        printf("%d ", test[i]);
    printf("\n");

    exit(EXIT_SUCCESS);
}
