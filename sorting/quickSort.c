#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 20

void insertionSort(int *a, int len) {
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

// "Hoare" partition
int partition(int *a, int low, int high) {
    int i = low, j = high + 1, pivot = a[low];  // pivot: a[low] 
    while(1) {
        while(a[++i] < pivot) 
            if(i == high) break;
        while(a[--j] > pivot) 
            if(j == low) break; 
        if(i >= j) 
            break;
        Swap(&a[i], &a[j]);
    }
    Swap(&a[j], &a[low]);
    return j;
}

// Recursive
void quickSortRecursive(int *a, int low, int high) {
    int len = high - low + 1;
    if(low >= high)
        return ;
    if(len <= 10) {
        insertionSort(a + low, len);
    } else {
        int p = partition(a, low, high);
        quickSortRecursive(a, low, p - 1);
        quickSortRecursive(a, p + 1, high);
    }
}

// Iterative
void quickSortIterative(int *a, int low, int high) {
    int pivot, top = -1, stack[high-low+1];
    stack[++top] = low;
    stack[++top] = high;
    while(top >= 0) {
        high = stack[top--];
        low = stack[top--];
        pivot = partition(a, low, high);
        if(pivot-1 > low) {
            stack[++top] = low;
            stack[++top] = pivot-1;
        }
        if(pivot+1 < high) {
            stack[++top] = pivot+1;
            stack[++top] = high;
        }
    }
}


int main(int argc, char *argv[]) {
    int i, test[N];
    srand((unsigned)time(NULL));
    for(i = 0; i < N; ++i)
      test[i] = rand() % 100;

    //quickSortRecursive(test, 0, N - 1);
    quickSortIterative(test, 0, N - 1);

    for(i = 0; i < N; ++i)
        printf("%d ", test[i]);
    printf("\n");
    return 0;
}
