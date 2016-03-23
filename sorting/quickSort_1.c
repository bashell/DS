#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100

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
    if(a[high] < a[low])
        Swap(&a[high], &a[low]);
    if(a[high] < a[center])
        Swap(&a[high], &a[center]); 
    if(a[low] > a[center])
        Swap(&a[low], &a[center]);
    // Now a[low] <= a[center] <= a[high]
    Swap(&a[center], &a[high-1]);  // move pivot to a[high-1]
    return a[high-1];
}

/*
 * "Median-of-Three" partition
 */
int partition(int *a, int low, int high) {
    int pivot = median_of_three(a, low, high);
    // a[low] must be lower than pivot
    // a[high] must be higher than pivot
    // a[high-1] is the pivot
    int i = low, j = high - 1;  
    while(1) {
        while(a[++i] < pivot) 
            if(i == high) break;
        while(a[--j] > pivot) 
            if(j == low) break; 
        if(i >= j) 
            break;
        Swap(&a[i], &a[j]);
    }
    Swap(&a[i], &a[high-1]);
    return i;
}

void quickSort(int *a, int low, int high) {
    int len = high - low + 1;
    if(low >= high)
        return ;
    if(len <= 10) {
        insertSort(a + low, len);
    } else {
        int p = partition(a, low, high);
        quickSort(a, low, p - 1);
        quickSort(a, p + 1, high);
    }
}

int main(int argc, char *argv[]) {
    int i, test[N];
    srand((unsigned)time(NULL));
    for(i = 0; i < N; ++i)
      test[i] = rand() % 100;
    quickSort(test, 0, N - 1);
    for(i = 0; i < N; ++i)
        printf("%d ", test[i]);
    printf("\n");
    return 0;
}
