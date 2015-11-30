#include <stdio.h>
#include <stdlib.h>

#define N 10

void merge(int a[], int tempArray[], int left, int mid, int right) {
    int i = left, j = mid, k = left;
    int numElements = right - left + 1;    // the size of tempArray

    while(i <= mid-1 && j <= right)
        if(a[i] <= a[j])
            tempArray[k++] = a[i++];
        else
            tempArray[k++] = a[j++];
    while(i <= mid-1)    // copy the remaining elements of the left side
        tempArray[k++] = a[i++];
    while(j <= right)    // copy the remaining elements of the right side
        tempArray[k++] = a[j++];
    for(i = 0; i < numElements; ++i, --right)
        a[right] = tempArray[right];
}

void mergeSort(int a[], int tempArray[], int left, int right) {
    int center;
    if(left < right) {
        center = (left + right) / 2;
        mergeSort(a, tempArray, left, center);    // recursive call
        mergeSort(a, tempArray, center + 1, right);
        merge(a, tempArray, left, center + 1, right);
    }
}

int main(int argc, char *argv[]) {
    int i;
    int test[N] = {1, 3, 2, 9, 10, 8, 4, 5, 6, 7};
    int *tempArray = malloc(N * sizeof(int));
    if(tempArray == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    mergeSort(test, tempArray, 0, N - 1);
    for(i = 0; i < N; ++i)
        printf("%d ", test[i]);
    printf("\n");
    free(tempArray);
    return 0;
}
