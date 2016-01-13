#include <stdio.h>
#include <stdlib.h>

/*
 * T(N) = O(N + K)
 */
void countingSort(int arr[], int n) {
    if(n <= 0)  return;
    int i, max = arr[0];
    for(i = 1; i < n; ++i)
        if(max < arr[i])
            max = arr[i];
    int *count = (int *)calloc(max+1, sizeof(int));
    if(NULL == count) {
        fprintf(stderr, "calloc error");
        exit(EXIT_FAILURE);
    }
    int *sorted = (int *)calloc(n, sizeof(int));
    if(NULL == sorted) {
        fprintf(stderr, "calloc error");
        exit(EXIT_FAILURE);
    }
    for(i = 0; i < n; ++i)  // 统计每个元素出现的总次数, 循环结束后count[i]等于值为i的元素个数
        ++count[arr[i]];
    for(i = 1; i <= max; ++i)  // 累加计数, 循环结束后count[i]代表有多少个元素的值是小于等于i的
        count[i] += count[i-1];
    /*
     * 对原数组中的每个元素arr[i], 在count数组中查出有几个元素是比arr[i]小的, 用count[arr[i]]表示
     * 若有m个元素比arr[i]小, 那么应该将arr[i]放在sorted数组的第m个位置上: sorted[m-1]
     */
    for(i = n-1; i >= 0; --i) {
        sorted[count[arr[i]]-1] = arr[i];  // 按这种方法放置, 相同元素的相对位置不变, 因此算法是稳定的
        --count[arr[i]];  // 放完一个arr[i], 小于等于arr[i]的总个数count[arr[i]]当然要减1
    }
    for(i = 0; i < n; ++i)  // 回写, 结束后arr有序
        arr[i] = sorted[i];
    free(count);
    free(sorted);
}

int main(int argc, char *argv[])
{
    int i;
    int test[10] = {3, 2, 2, 1, 5, 8, 9, 9, 7, 0};
    countingSort(test, 10);
    for(i = 0; i < 10; ++i)
        printf("%d ", test[i]);
    printf("\n");
    return 0;
}
