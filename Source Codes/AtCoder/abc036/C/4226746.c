#include<stdio.h>
#include<stdlib.h>
int a[100005];
int asc(const void *x, const void *y)
{
    return a[*(int *)x] - a[*(int *)y];
}
int main()
{
    int n;
    scanf("%d", &n);
    int i;
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    int b[100005];
    for (i = 0; i < n; i++)
        b[i] = i;
    qsort(b, n, sizeof(int), asc);
    int c[100005];
    c[0] = 0;
    for (i = 1; i < n; i++)
    {
        if (a[b[i]] == a[b[i - 1]])
            c[i] = c[i - 1];
        else
            c[i] = c[i - 1] + 1;
    }
    int d[100005];
    for (i = 0; i < n; i++)
        d[b[i]] = c[i];
    for (i = 0; i < n; i++)
        printf("%d\n", d[i]);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &n);
     ^
./Main.c:14:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d", &a[i]);
         ^