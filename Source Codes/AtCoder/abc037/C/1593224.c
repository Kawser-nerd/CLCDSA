#include <stdio.h>
static long n, k, a, i, sum;
long min2(long a, long b) {
    return a <= b ? a : b;
}
long min(long a, long b, long c, long d) {
    return min2(min2(a, b), min2(c, d));
}
int main(void) {
    scanf("%ld%ld", &n, &k);
    for (i = 0; i < n; ++i) {
        scanf("%ld", &a);
        sum += a * min(i + 1, n - k + 1, n - i, k);
    }
    printf("%ld\n", sum);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%ld%ld", &n, &k);
     ^
./Main.c:12:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%ld", &a);
         ^