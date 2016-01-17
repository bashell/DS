#include <stdio.h>

// recursive version
long RussianPeasant1(long m, long n) {
    if(m % 2 == 0)
        return RussianPeasant1(m/2, n*2);
    else if(m == 1)
        return n;
    else
        return RussianPeasant1((m-1)/2, n*2) + n;
}

// iterative version
long RussianPeasant2(long m, long n) {
    long p = 0;
    while(m != 1) {
        if(m % 2)
            p += n;
        m /= 2;
        n *= 2;
    }
    return p + n;
}

int main()
{
    long res1 = RussianPeasant1(26, 47);
    long res2 = RussianPeasant2(47, 26);
    printf("%ld %ld\n", res1, res2);
    return 0;
}
