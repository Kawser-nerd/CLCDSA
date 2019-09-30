#include <stdio.h>
int is_takahashi(long n) {
    long tmp, x, depth = 0;
    for (tmp = n; tmp > 0; tmp /= 2) ++depth;
    x = 1;
    if (depth % 2) {
        while (1) {
            x = 2 * x + 1;
            if (x > n) return 0;
            x = 2 * x;
            if (x > n) return 1;
        }
    } else {
        while (1) {
            x = 2 * x;
            if (x > n) return 0;
            x = 2 * x + 1;
            if (x > n) return 1;
        }
    }
}
int main(void) {
//    int i;
    long n;
    scanf("%ld", &n);
//    for (i = 1; i <= 100; ++i) {
//        printf("%d%c, ", i, is_takahashi(i) ? 't' : 'a');
//    }
//    putchar('\n');
    if (is_takahashi(n))
        puts("Takahashi");
    else
        puts("Aoki");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:25:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%ld", &n);
     ^