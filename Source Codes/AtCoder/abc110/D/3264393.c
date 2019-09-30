#include <stdio.h>

#define MODULUS  (1000 * 1000 * 1000 + 7)  /* Note that it is prime. */
#define N_FACT   30   /* 10**9 \sim 2**30 */

int fact[N_FACT];
int n_fact = 0;

void factorized(int M)
{
    n_fact = 0;
    int d = 2;
    while (d <= M) {
        int count = 0;
        while (M % d == 0) {
            M /= d;
            count++;
        }
        if (count > 0) {
            fact[n_fact++] = count;
        }
        d++;
    }
}

/* modular multiplicative inverse a^{-1} (mod m) */
long inverse(long a)
{
    /* a^{-1} == a^{m-2} mod m for a prime m by Euler's theorem. */
    long powa = a;  /* a^{2^i} (mod m) */
    long x = 1;
    int i;
    for (i = 0; i < 30; i++) {
        if ((MODULUS - 2) & (1 << i)) {
            x = x * powa % MODULUS;
        }
        powa = powa * powa % MODULUS;
    }
    return x;
}

long tetra(int n, int m)
{
    long x = 1;
    long y = 1;
    int i;
    for (i = 1; i < n; i++) {
        x = x * (m + i - 1) % MODULUS;
        y = y * i           % MODULUS;
    }
    return x * inverse(y) % MODULUS;
}

int main()
{
    int N, M;
    long x;
    int i;

    scanf("%d%d", &N, &M);

    factorized(M);
    x = 1;
    for (i = 0; i < n_fact; i++) {
        x *= tetra(N, fact[i] + 1);
        x %= MODULUS;
    }

    printf("%ld\n", x);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:60:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d", &N, &M);
     ^