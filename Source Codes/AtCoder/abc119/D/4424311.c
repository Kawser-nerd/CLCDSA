#define NDEBUG

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>

typedef int64_t len_t;
len_t len_abs(len_t x)
{
    return x >= 0? x: -x;
}
const len_t INF = 10E11;

// https://golang.org/src/sort/search.go?s=2246:2286#L49
int my_bsearch(len_t a[], int N, len_t needle)
{
    // split array into left set (L) and right set (R)

    // k_is_in_L(-1) -> true
    // k_is_in_L(N) -> false
    #define k_is_in_L(k) ((k != N) && ((k == -1) || a[k] < needle))

    // In this function, (i-1) is always in L,
    //                   and j is always in R.
    int i = 0; // initial i-1 == -1 --> L
    int j = N; // initial j == N --> R
    while (i < j) {
        int m = (i + j) / 2;
        // minimum of j => i + 1 (because i < j)
        // minimum of m => (i + i + 1) / 2 => i
        // ==> i <= m < j
        assert(m >= 0);
        assert(m < N);
        if (k_is_in_L(m)) {
            i = m + 1;
            // i-1 is m, so (i-1) is in L
        } else {
            j = m;
            // m is in R, so j is in R
        }
    }
    // i == j, i-1 is in L, j is in R
    //  => The smallest element of R is i.
    // note: this function may return N.
    return i;
    #undef k_is_in_L
}

/*
len_t *readlist_alloc(int size)
{
    int i, z;
    len_t *a = calloc(size, sizeof(a[0]));
    for (i = 0; i < size; i ++) {
        z = scanf("%ld", &a[i]);
    }
    return a;
}
*/

len_t *readlist_alloc_special(int size)
{
    int i, z;
    len_t *a_orig = calloc(size + 2, sizeof(len_t));
    len_t *a = a_orig + 1;
    for (i = 0; i < size; i ++) {
        z = scanf("%ld", &a[i]);
    }
    a[-1] = -INF;
    a[size] = INF;
    return a;
}

void print_problem(int A, int B, int Q, len_t S[], len_t T[], len_t X[])
{
    int i;
    printf("%d %d %d\n", A, B, Q);
    puts("S: ");
    for (i = 0; i < A; i ++) {
        printf("%ld ", S[i]);
    }
    puts("\nT: ");
    for (i = 0; i < B; i ++) {
        printf("%ld ", T[i]);
    }
    puts("\nQ: ");
    for (i = 0; i < Q; i ++) {
        printf("%ld ", X[i]);
    }
    printf("\n");
}

len_t distance(len_t x, len_t p0, len_t p1)
{
    // x -> p0
    len_t d0 = len_abs(p0 - x);
    // p0 -> p1
    len_t d1 = len_abs(p1 - p0);
    return d0 + d1;
}

int main()
{
    int A, B, Q, z;
    len_t *S, *T, *X;
    z = scanf("%d%d%d", &A, &B, &Q);
    S = readlist_alloc_special(A);
    T = readlist_alloc_special(B);
    X = readlist_alloc_special(Q);
    //print_problem(A, B, Q, S, T, X);
    int i;
    for (i = 0; i < Q; i++) {
        len_t x = X[i];
        int sr = my_bsearch(S, A, x);
        int sl = sr - 1;
        int tr = my_bsearch(T, B, x);
        int tl = tr - 1;
        len_t slv = S[sl];
        len_t srv = S[sr];
        len_t tlv = T[tl];
        len_t trv = T[tr];
        //printf("%ld (%ld %ld) (%ld %ld)\n", x, slv, srv, tlv, trv);
        //printf(" (%d %d) (%d %d)\n", sl, sr, tl, tr);
        len_t dists[8] = {0};
        len_t min = 10E11;
        len_t tmp;
        #define UPDATE_MIN do {if (tmp < min) min = tmp;} while(0)
        // choose l->l l->r r->l r->r
        //        l<-l l<-r r<-l r<-r
        tmp = distance(x, slv, tlv); UPDATE_MIN;
        tmp = distance(x, slv, trv); UPDATE_MIN;
        tmp = distance(x, srv, tlv); UPDATE_MIN;
        tmp = distance(x, srv, trv); UPDATE_MIN;
        tmp = distance(x, tlv, slv); UPDATE_MIN;
        tmp = distance(x, tlv, srv); UPDATE_MIN;
        tmp = distance(x, trv, slv); UPDATE_MIN;
        tmp = distance(x, trv, srv); UPDATE_MIN;

        printf("%ld\n", min);
    }
    return 0;
}