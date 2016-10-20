#include <stdio.h>

// a^b % c. 例如当c = 1000时, 求a^b的末三位构成的整数

/**
 * 模拟: T(n) = O(b)
 */
int pow_mod1(int a, int b, int c) {
    int res = 1;
    for(int i = 0; i < b; ++i) // (a^b)%c = ((a%c)^b)%c
        res = res * a % c;
    return res;
}

/**
 * 快速幂: T(n) = O(logb)
 */
int pow_mod2(int a, int b, int c) {
    if(b == 0) return 1;
    int res = pow_mod2(a, b/2, c);
    res = res * res % c;
    if(b & 1) res = res * a % c;
    return res;
}

int main()
{
    int a, b, c;
    while(3 == scanf("%d%d%d", &a, &b, &c))
        printf("%d\n%d\n", pow_mod1(a, b, c), pow_mod2(a, b, c));
    return 0;
}
