#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * next[len]代表pattern[0..len-1]的真前缀和真后缀的交集中，元素的最大长度
 *
 * 例如，pattern: a b a b a c a
 *          next: 0 0 1 2 3 0 1 
 */
void computeNextArray(char *pattern, int *next) {
    int m = strlen(pattern);
    int i = 1, len = 0; 
    next[0] = 0;
    while(i < m) {  // i = 1, 2, ..., m-1
        if(pattern[len] == pattern[i]) {
            ++len;
            next[i] = len;
            ++i;
        } else {
            if(len == 0) {
                next[i] = 0;
                ++i;
            } else {
                len = next[len-1];
            }
        }
    }
}

void kmp(char *pattern, char *txt) {
    int m = strlen(pattern), n = strlen(txt);
    int i, j;
    int *next = (int *)malloc(m * sizeof(int));
    if(NULL == next) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    computeNextArray(pattern, next);
    i = j = 0;
    while(i < n) {
        if(pattern[j] == txt[i])
            ++i, ++j;
        if(j == m) {
            printf("Pattern occurs at index %d\n", i-j);
            j = next[j-1];
        } else if(i < n && pattern[j] != txt[i]) {
            if(j == 0)
                ++i;
            else
                j = next[j-1];
        }
    }
    free(next);
}

int main()
{
    char *pattern = "aab";
    char *txt = "acaabcabaabbc";
    kmp(pattern, txt);
    return 0;
}
