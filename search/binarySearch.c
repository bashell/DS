#include <stdio.h>

// recursive version
int binarySearch1(int arr[], int left, int right, int x) {
    if(left <= right) {
        int mid = left + (right - left) / 2;
        if(arr[mid] == x)  
            return mid;
        if(arr[mid] > x) 
            return binarySearch1(arr, left, mid-1, x);
        else
            return binarySearch1(arr, mid+1, right, x);
    }
    return -1;
}

// iterative version
int binarySearch2(int arr[], int left, int right, int x) {
    while(left <= right) {
        int mid = left + (right - left) / 2;
        if(arr[mid] == x)
            return mid;
        if(arr[mid] < x)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int main()
{
    int arr[] = {8, 4, 15, 2, 17, 21, 6, 43, 59, 10};
    int sz = sizeof(arr) / sizeof(arr[0]);
    int index, x = 15;
    if((index = binarySearch2(arr, 0, sz-1, x)) != -1)
        printf("%d\n", arr[index]);
    else
        printf("Not found!\n");
    return 0;
}
