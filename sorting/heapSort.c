#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100

// 左孩子(由于数组下标从0开始)
#define LeftChild(i) (2 * (i) + 1)


/* 
 * 堆修复函数(维护最大堆性质)
 * i: 待修复结点的下标
 * len: 数组长度
 */
void heapAdjust(int *arr, int i, int len) {
    int child, temp;
    for( ; LeftChild(i) < len; i = child) {
        child = LeftChild(i);
        // 如果有两个子节点， 则令child指向值较大的结点
        if(child != len - 1 && arr[child + 1] > arr[child])
            ++child;
        // 判断是否大于父结点的值
        if(arr[i] < arr[child]) {    
            temp = arr[i];
            arr[i] = arr[child];
            arr[child] = temp;
        } else {
            break;
        }
    }
}

void heapSort(int *arr, int len) {
    int i, temp;
    /* 
     * 建堆
     * 从最右侧的非叶结点开始逐步修复堆
     * 循环结束后arr[0]为最大元素
     */
    for(i = len / 2; i >= 0; --i)
        heapAdjust(arr, i, len);
    /*
     * 将最大元素换至本轮循环的最后位置, 然后进行堆修复
     */
    for(i = len - 1; i > 0; --i) {
        temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapAdjust(arr, 0, i);
    }
}

int main(int argc, char *argv[]) 
{
    int i, test[N];
    srand((unsigned)time(NULL));
    for(i = 0; i < N; ++i)
      test[i] = rand() % 100;
    heapSort(test, N);
    for(i = 0; i < N; ++i)
        printf("%d ", test[i]);
    printf("\n");
    return 0;
}
