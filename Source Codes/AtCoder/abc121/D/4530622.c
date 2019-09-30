#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <math.h>

long long g(long long x)
{
    long long a;
    long long y;

    // f(0, x & ~0x03LL) = x & ~0x03LL
    y = x & ~0x03LL;

    for (a = y + 1; a <= x; a++) {
        y ^= a;
    }

    return y;
}

int main(int argc, char *argv[])
{
    long long a, b;
    long long ans;

    scanf("%lld %lld", &a, &b);

    // f(a, b) = f(0, a - 1) ^ f(0, b) ???
    ans = g(a - 1) ^ g(b);

    printf("%lld\n", ans);

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:27:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld %lld", &a, &b);
     ^