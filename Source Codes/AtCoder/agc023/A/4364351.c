#include<stdio.h>
#include<stdlib.h>
int asc(const void *a, const void *b)
{
    long *A = (long int *)a;
    long *B = (long *)b;
    if (*A > *B)return 1;
    if (*A < *B)return -1;
    return 0;
}
int main()
{
    int n;
    scanf("%d", &n);
    int i;
    long a[200005];
    for (i = 0; i < n; i++)
        scanf("%ld", &a[i]);
    long sum[200005];
    sum[0] = 0;
    for (i = 0; i < n; i++)
        sum[i + 1] = sum[i] + a[i];
    qsort(sum, n + 1, sizeof(long), asc);
    unsigned long long int ans = 0, x;
    x = 1;
    for (i = 1; i < n + 1; i++)
    {
        if (sum[i] == sum[i - 1])
            x++;
        else
        {
            ans += x * (x - 1) / 2;
            x = 1;
        }
    }
    ans += x * (x - 1) / 2;
    printf("%lld\n", ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:14:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &n);
     ^
./Main.c:18:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%ld", &a[i]);
         ^