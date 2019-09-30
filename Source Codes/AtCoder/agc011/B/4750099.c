#include<stdio.h>
#include<stdlib.h>
int asc(const void *a, const void *b)
{
    long *A = (long *)a;
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
    long long int a[100005];
    for (i = 0; i < n; i++)
        scanf("%lld", &a[i]);
    qsort(a, n, sizeof(long long int), asc);
    long long int sum = 0;
    for (i = 0; i < n - 1; i++)
        sum += a[i];
    int ans = 1;
    for (i = n - 1; i > 0; i--)
    {
        if (2 * sum < a[i])
            break;
        ans++;
        sum -= a[i - 1];
    }
    printf("%d\n", ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:14:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &n);
     ^
./Main.c:18:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%lld", &a[i]);
         ^