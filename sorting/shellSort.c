#include <stdio.h>

void shellSort(int a[], int len) {
    int i, j, increment;    // increment为增量步长
    int temp;

    // Using Shell's increments(not very efficient)
    for(increment = len / 2; increment > 0; increment /= 2) {
        for(i = increment; i < len; i++) {
            temp = a[i];
            for(j = i; j >= increment; j -= increment) {
                if(temp < a[j - increment])
                    a[j] = a[j - increment];
                else
                    break;  // 用于跳过j -= increment的操作
            }
            a[j] = temp;
        }
    }
}

int main(int argc, char *argv[]) {
    int i;
    int test[10] = {1, 3, 2, 9, 10, 8, 4, 5, 6, 7};
    shellSort(test, 10);
    for(i = 0; i < 10; i++)
        printf("%d ", test[i]);
    printf("\n");
    return 0;
}
