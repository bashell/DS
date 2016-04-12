#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 20

// 左孩子(由于数组下标从0开始)
#define LeftChild(i) (2 * (i) + 1)

void mySwap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

/* 
 * 大根堆
 *
 * i  : 待修复结点的下标
 * len: 数组长度
 */
void heapAdjust1(int *arr, int i, int len) {
    int child;
    for( ; LeftChild(i) < len; i = child) {
        child = LeftChild(i);
        // 如果有两个子节点， 则令child指向值较大的结点
        if(child < len - 1 && arr[child + 1] > arr[child])
            ++child;
        // 判断是否大于父结点的值
        if(arr[child] > arr[i])
            mySwap(&arr[i], &arr[child]);
        else 
            break;
    }
}


// 升序
void heapSort1(int *arr, int len) {
    int i;
    /* 
     * 建堆
     * 从最后一个非叶结点开始逐步修复堆
     * 循环结束后arr[0]为最大元素
     */
    for(i = len / 2; i >= 0; --i)
        heapAdjust1(arr, i, len);
    /*
     * 将root换至本轮循环的最后位置, 然后进行堆修复
     */
    for(i = len - 1; i > 0; --i) {
        mySwap(&arr[0], &arr[i]);
        heapAdjust1(arr, 0, i);
    }
}



/* 
 * 小根堆
 *
 * i  : 待修复结点的下标
 * len: 数组长度
 */
void heapAdjust2(int *arr, int i, int len) {
    int child;
    for( ; LeftChild(i) < len; i = child) {
        child = LeftChild(i);
        // 如果有两个子节点， 则令child指向值较小的结点
        if(child < len - 1 && arr[child + 1] < arr[child])
            ++child;
        // 判断是否小于父结点的值
        if(arr[child] < arr[i])
            mySwap(&arr[child], &arr[i]);
        else 
            break;
    }
}

// 降序
void heapSort2(int *arr, int len) {
    int i, temp;
    /* 
     * 建堆
     * 从最后一个非叶结点开始逐步修复堆
     * 循环结束后arr[0]为最小元素
     */
    for(i = len / 2; i >= 0; --i)
        heapAdjust2(arr, i, len);
    /*
     * 将root换至本轮循环的最后位置, 然后进行堆修复
     */
    for(i = len - 1; i > 0; --i) {
        mySwap(&arr[0], &arr[i]);
        heapAdjust2(arr, 0, i);
    }
}


int main(int argc, char *argv[]) 
{
    int i, test[N];
    srand((unsigned)time(NULL));

    for(i = 0; i < N; ++i)
      test[i] = rand() % 100;
    heapSort1(test, N);
    for(i = 0; i < N; ++i)
        printf("%d ", test[i]);
    printf("\n\n");

    for(i = 0; i < N; ++i)
      test[i] = rand() % 100;
    heapSort2(test, N);
    for(i = 0; i < N; ++i)
        printf("%d ", test[i]);
    printf("\n");

    return 0;
}
