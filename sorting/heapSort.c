#include <stdio.h>

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
        if(child < len - 1 && arr[child + 1] > arr[child])    // 得到两个子结点中值较大的那个
            child++;
        if(arr[i] < arr[child]) {    // 判断是否大于父结点的值
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
    int i;
    int test[10] = {1, 3, 2, 9, 10, 8, 4, 5, 6, 7};
    heapSort(test, 10);
    for(i = 0; i < 10; ++i)
        printf("%d ", test[i]);
    printf("\n");
    return 0;
}
