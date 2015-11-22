#include <stdio.h>

void selectionSort(int *a, int len) {
    int i, j;
    int min_index;
    int temp;
    // 选择排序每轮都将本轮处理的最小元素放到最终的位置.
    for(i = 0; i < len - 1; ++i) {
        min_index = i;
        for(j = i + 1; j < len; ++j)
            if(a[j] < a[min_index])
                min_index = j;
        // 发现新min_index时, 进行swap操作.
        if(min_index != i) {  
            temp = a[i];
            a[i] = a[min_index];
            a[min_index] = temp;
        }
    }
}

int main(int argc, char *argv[]) 
{
    int i;
    int test[10] = {1, 3, 2, 9, 10, 8, 4, 5, 7, 6};
    selectionSort(test, 10);
    for(i = 0; i < 10; ++i)
        printf("%d ", test[i]);
    printf("\n");
    return 0;    
}
