#include <stdio.h>

// 左孩子(由于数组下标从0开始)
#define LeftChild(i) (2 * (i) + 1)


// 构造大根堆
void heapAdjust(int arr[], int i, int len) {
    int child;
    int temp;

    for( ; LeftChild(i) < len; i = child) {
        child = LeftChild(i);
        if(child < len - 1 && arr[child + 1] > arr[child])    // 得到两个子结点中值较大的那个
            child++;
        if(arr[i] < arr[child]) {    // 判断是否大于父结点的值
            temp = arr[i];
            arr[i] = arr[child];
            arr[child] = temp;
        }
        else
            break;
    }
}

void heapSort(int arr[], int len) {
    int i;
    int temp;

    // 建堆. 循环结束后arr[0]为最大元素.
    for(i = len / 2; i >= 0; i--)    
        heapAdjust(arr, i, len);

    for(i = len - 1; i > 0; i--) {
        // 将最大元素换至本轮循环的最后位置.
        temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        // 缩小堆调整范围.
        heapAdjust(arr, 0, i);
    }
}

int main(int argc, char *argv[]) {
    int i;
    int test[10] = {1, 3, 2, 9, 10, 8, 4, 5, 6, 7};
    heapSort(test, 10);
    for(i = 0; i < 10; i++)
        printf("%d ", test[i]);
    printf("\n");
    return 0;
}
