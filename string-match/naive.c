#include <stdio.h>
#include <string.h>

// T(n) = O((n-m+1)m)
void naive(char *pattern, char *txt) {
    int m = strlen(pattern), n = strlen(txt);
    int i, j;
    for(i = 0; i <= n - m; ++i) {
        int j = 0;
        while(j < m && pattern[j] == txt[i + j])
            ++j;
        if(j == m)
            printf("Pattern occurs at index %d\n", i);
    }
}

int main()
{
    char *pattern = "aab";
    char *txt = "acaabcabaabbc";
    naive(pattern, txt);
    return 0;
}
