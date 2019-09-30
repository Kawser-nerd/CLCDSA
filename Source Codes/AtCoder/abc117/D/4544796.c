#define NDEBUG

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>

typedef uint64_t num_t;

const int DBG = 0;

num_t num_abs(num_t x)
{
    return x >= 0? x: -x;
}
const num_t INF = 10E11;

num_t *readlist_alloc(int size)
{
    int i;
    num_t *a = calloc(size, sizeof(a[0]));
    for (i = 0; i < size; i ++) {
        int _ = scanf("%ld", &a[i]);
    }
    return a;
}
void print_problem(int N, num_t K, num_t A[])
{
    int i;
    printf("%d %lu\n", N, K);
    puts("A: ");
    for (i = 0; i < N; i ++) {
        printf("%lu ", A[i]);
    }
    printf("\n");
}

int get_num_bits(num_t n)
{
    int i = 0;
    assert(n >= 0);
    while(n) {
        i++;
        n = n >> 1ULL;
    }
    return i;
}

num_t get_x_template(int nbits, int N, num_t A[])
{
    int i, j;
    num_t X = 0ULL;
    for (i = 0; i < nbits; i++) {
        int c = 0;
        for (j = 0; j < N; j++)
            c += (A[j] & (1ULL << i)) >> i;
        if (c < N - c)
            X |= (1ULL << i);
    }
    return X;
}

num_t func(num_t A[], int N, num_t X)
{
    int i;
    num_t ret = 0ULL;
    for (i = 0; i < N; i++)
        ret = ret + (X ^ A[i]);
    return ret;
}

int main()
{
    int N;
    num_t K;
    num_t *A;
    int _ = scanf("%d%lu", &N, &K);
    A = readlist_alloc(N);
    int nbits = 40;
    int K_bits = get_num_bits(K);
    if (DBG) print_problem(N, K, A);
    if (DBG) printf("K %lu, bit %d\n", K, nbits);
    int i;
    num_t X_template = get_x_template(nbits, N, A);
    if (DBG) printf("X_template %lu\n", X_template);
    num_t X_max = 0ULL;
    num_t f_max = func(A, N, X_max);
    for (i = 0; i < nbits; i++) {
        num_t mask_sp = ~(1ULL<<i);
        num_t mask_lo = (1ULL<<i) - 1ULL;
        num_t mask_hi = ~mask_lo;
        //if (DBG) printf("%016lx %016lx %016lx\n", mask_sp, mask_lo, mask_hi);
        //if (!(K & mask_sp)) continue;
        num_t X = ((K & mask_hi) | (X_template & mask_lo)) & mask_sp;
        if (X > K)
            continue;
        num_t fx = func(A, N, X);
        if (DBG) printf("i %d X fx %lu %lu\n", i, X, fx);
        if (fx > f_max) {
            f_max = fx;
            X_max = X;
        }
    }
    if (DBG) printf("X_max %lu\n", X_max);
    printf("%lu\n", f_max);
    return 0;
}