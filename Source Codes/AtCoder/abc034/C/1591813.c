#include <stdio.h>
#define M 1000000007
// Returns a^b mod p.
long pow_mod(long a, long b, long p) {
    long d;
    if (b == 0)
        return 1;
    if (b % 2 == 0) {
        d = pow_mod(a, b / 2, p);
        return d * d % p;
    } else {
        d = pow_mod(a, b - 1, p);
        return a * d % p;
    }
}
static long w, h;
int main(void) {
    long i, acc = 1;
    scanf("%ld%ld", &w, &h);
    --w;
    --h;
    for (i = 1; i <= h + w; ++i) {
        acc *= i;
        acc %= M;
    }
    for (i = 1; i <= h; ++i) {
        acc *= pow_mod(i, M - 2, M);    // Fermat's little theorem.
        acc %= M;
    }
    for (i = 1; i <= w; ++i) {
        acc *= pow_mod(i, M - 2, M);
        acc %= M;
    }
    printf("%ld\n", acc);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:19:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%ld%ld", &w, &h);
     ^