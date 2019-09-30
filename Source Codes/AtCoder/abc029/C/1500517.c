#include <stdio.h>
static char s[] = "abc";
static int n;
int main(void) {
    int i, j, max = 1, div, mod;
    scanf("%d", &n);
    for (i = 0; i < n; ++i)
        max *= 3;
    for (i = 0; i < max; ++i) {
        mod = max;
        div = mod / 3;
        for (j = 0; j < n; ++j) {
            printf("%c", s[i % mod / div]);
            mod /= 3;
            div /= 3;
        }
        putchar('\n');
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &n);
     ^