#include <stdio.h>

void countingSort(int arr[], int n, int exp) {
    int i, count[10] = {0};
    int sorted[n];
    for(i = 0; i < 10; ++i)
        ++count[(arr[i]/exp) % 10];
    for(i = 1; i < 10; ++i)
        count[i] += count[i-1];
    for(i = n-1; i >= 0; --i) {
        sorted[count[(arr[i]/exp) % 10] - 1] = arr[i];
        --count[(arr[i]/exp) % 10];
    }
    for(i = 0; i < n; ++i)
        arr[i] = sorted[i];
}

void radixSort(int arr[], int n) {
    int i, exp;
    int max = arr[0];
    for(i = 1; i < n; ++i)
        if(max < arr[i])
            max = arr[i];
    for(exp = 1; max/exp > 0; exp *= 10)  // 先按最低有效位进行计数排序
        countingSort(arr, n, exp);
}

int main()
{
    int i;
    int test[10] = {3, 2, 2, 1, 5, 8, 9, 9, 7, 0};
    radixSort(test, 10);
    for(i = 0; i < 10; ++i)
        printf("%d ", test[i]);
    printf("\n");
    return 0;
}
