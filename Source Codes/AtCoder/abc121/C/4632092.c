#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    int *p = *(int**)a; int *q = *(int**)b;
    if( p[0] > q[0] )       { return 1; }
    else if( p[0] < q[0] )  { return -1; }
    else                    { return 0; }
}

int main()
{
    int i, n, m, temp;
    unsigned long long mny;
    scanf("%d %d", &n, &m);
    int **a = (int **)malloc(n * sizeof(int *));
    a[0] = (int *)malloc(n*2*sizeof(int));
    for(i = 1; i < n; ++i) { a[i] = a[0] + i*2; }
    for(i = 0; i < n; ++i) { scanf("%d %d", &a[i][0], &a[i][1]); }
    qsort(a, n, sizeof(int*), cmp);
    //for(i = 0; i < n; ++i) { printf("%d %d\n", a[i][0], a[i][1]); }

    //printf("---------\n");
    i = 0; mny = (unsigned long long)0;
    for(i = 0; (i < n && m > 0); ++i) {
        temp = ( a[i][1] <= m) ? a[i][1] : m;
        mny += (unsigned long long)a[i][0] * (unsigned long long)temp;
        m -= temp;
    }
    printf("%llu\n", mny);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:15:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d", &n, &m);
     ^
./Main.c:19:30: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     for(i = 0; i < n; ++i) { scanf("%d %d", &a[i][0], &a[i][1]); }
                              ^