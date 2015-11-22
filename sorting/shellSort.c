#include <stdio.h>

/* 
 * 增量递减排序
 * 这里increment每次缩小一半(not very efficient)
 */
void shellSort1(int *a, int len) {
    int i, j, increment;    // increment: 增量步长
    int temp;
    for(increment = len / 2; increment > 0; increment /= 2) {
        // Insert a[i] among a[i-increment], a[i-2*increment], a[i-3*increment], ...
        for(i = increment; i < len; ++i) {
            temp = a[i];
            for(j = i; j >= increment; j -= increment) {
                if(temp < a[j - increment])
                    a[j] = a[j - increment];
                else
                    break;
            }
            a[j] = temp;
        }
    }
}

/* 
 * Knuth's increment sequence: 1, 4, 13, 40, 121, 364, 1093, ...
 */
void shellSort2(int *a, int len) {
    int i, j;   
    int temp, h = 1;
    while(h < len / 3)  
        h = 3 * h + 1;  
    for( ; h > 0; h /= 3) {
        // h-sort the array
        for(i = h; i < len; ++i) {
            // Insert a[i] among a[i-h], a[i-2*h], a[i-3*h], ...
            for(j = i; j >= h && a[j] < a[j - h]; j -= h) {
                temp = a[j];
                a[j] = a[j - h];
                a[j - h] = temp;
            }
        }
    }
}

int main(int argc, char *argv[]) {
    int i;
    int test[10] = {1, 3, 2, 9, 10, 8, 4, 5, 6, 7};
    shellSort2(test, 10);
    for(i = 0; i < 10; ++i)
        printf("%d ", test[i]);
    printf("\n");
    return 0;
}
