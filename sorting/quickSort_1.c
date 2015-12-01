#include <stdio.h>

#define N 20

void insertSort(int *a, int len) {
    int i, j, temp;
    for(i = 1; i < len; ++i) {
        temp = a[i];
        for(j = i - 1; j >= 0 && a[j] > temp; --j)
            a[j + 1] = a[j];    
        a[j + 1] = temp;    
    }
}

void Swap(int *left, int *right) {
    int temp = *left;
    *left = *right;
    *right = temp;
}

/*
 * Get the median of a[low], a[center] and a[high].
 */
int median_of_three(int *a, int low, int high) {
    int center = (low + high) / 2;
    if(a[high] > a[low])
        Swap(&a[high], &a[low]);
    if(a[high] > a[center])
        Swap(&a[high], &a[center]);  // Now a[high] is the biggest of the three values.
    if(a[low] < a[center])
        Swap(&a[low], &a[center]);
    return a[low];
}

/*
 * "Median-of-Three" partition
 */
int partition(int *a, int low, int high) {
    int i = low, j = high + 1;
    int pivot = median_of_three(a, low, high);
    while(1) {
        while(a[++i] < pivot) 
            if(i == high) break;
        while(a[--j] > pivot) 
            if(j == low) break; 
        if(i >= j) 
            break;
        Swap(&a[i], &a[j]);
    }
    Swap(&a[j], &a[0]);
    return j;
}

void quickSort(int *a, int low, int high) {
    int len = high - low + 1;
    if(len <= 10) {
        insertSort(a + low, len);
    } else {
        int p = partition(a, low, high);
        quickSort(a, low, p - 1);
        quickSort(a, p + 1, high);
    }
}

int main(int argc, char *argv[]) {
    int i;
    int test[N] = {7, 3, 2, 9, 10, 8, 4, 5, 11, 6, 1, 15, 14, 13, 12, 20, 19, 17, 18, 16};
    quickSort(test, 0, N - 1);
    for(i = 0; i < N; ++i)
        printf("%d ", test[i]);
    printf("\n");
    return 0;
}
