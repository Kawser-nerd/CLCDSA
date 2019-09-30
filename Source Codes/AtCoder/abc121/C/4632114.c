#include <stdio.h>
#include <stdlib.h>

#define ULL unsigned long long

int cmp(const void *a, const void *b) {
    int *p = *(int**)a; int *q = *(int**)b;
    if( p[0] > q[0] )       { return 1; }
    else if( p[0] < q[0] )  { return -1; }
    else                    { return 0; }
}

int main()
{
    int i, n, m, temp;
    ULL mny;
    scanf("%d %d", &n, &m);
    int **a = (int **)malloc(n * sizeof(int *));
    a[0] = (int *)malloc(n*2*sizeof(int));
    for(i = 1; i < n; ++i) { a[i] = a[0] + i*2; }
    for(i = 0; i < n; ++i) { scanf("%d %d", &a[i][0], &a[i][1]); }
    qsort(a, n, sizeof(int*), cmp);
    //for(i = 0; i < n; ++i) { printf("%d %d\n", a[i][0], a[i][1]); }

    //printf("---------\n");
    i = 0; mny = (ULL)0;
    for(i = 0; (i < n && m > 0); ++i) {
        temp = ( a[i][1] <= m) ? a[i][1] : m;
        mny += (ULL)a[i][0] * (ULL)temp;
        m -= temp;
    }
    printf("%llu\n", mny);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:17:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d", &n, &m);
     ^
./Main.c:21:30: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     for(i = 0; i < n; ++i) { scanf("%d %d", &a[i][0], &a[i][1]); }
                              ^