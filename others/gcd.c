#include <stdio.h>

int gcd(int a, int b) {
    int c = a % b;
    while(c) {
        a = b;
        b = c;
        c = a % b;
    }
    return b;
}

int main()
{
    int a = 128;
    int b = 56;
    printf("%d\n", gcd(a, b));
    return 0;
}
