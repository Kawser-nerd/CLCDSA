#include <stdio.h>
#include <stdlib.h>

#define MaxN 1000

int cmp1 (const void *a, const void *b)
{
    long *x = (long *)a;
    long *y = (long *)b;
    if (*x > *y)
       return 1;
    if (*x < *y)
       return -1;
    return 0;
}

int cmp2 (const void *a, const void *b)
{
    long *x = (long *)a;
    long *y = (long *)b;
    if (*x > *y)
       return -1;
    if (*x < *y)
       return 1;
    return 0;
}

int main ()
{
    long x[MaxN], y[MaxN];
    long long total;
    int testCase, i, n, t;
    FILE *in = fopen ("A.in", "r");
    FILE *out = fopen ("B.in", "r");
    fscanf(in, "%d\n", &t);
    for (testCase = 1; testCase <= t; testCase++)
    {
        fscanf(in, "%d\n", &n);
        for (i = 0; i < n; i++)
            fscanf(in, "%ld", &x[i]);
        for (i = 0; i < n; i++)
            fscanf(in, "%ld", &y[i]);
        
        qsort(x, n, sizeof(x[0]), cmp1);
        qsort(y, n, sizeof(y[0]), cmp2);
        
        total = 0;
        for (i = 0; i < n; i++)
            total = total + (long long) (x[i] * y[i]);
        printf("Case #%d: %lld\n", testCase, total);
    }
    return 0;
}
