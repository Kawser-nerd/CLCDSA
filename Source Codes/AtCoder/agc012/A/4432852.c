#include<stdio.h>
#include<stdlib.h>
int asc(const void *a, const void *b)
{
    return *(int *)b - *(int *)a;
}
int main()
{
    int n;
    scanf("%d", &n);
    int i;
    int a[300005];
    for (i = 0; i < 3 * n; i++)
        scanf("%d", &a[i]);
    qsort(a, 3 * n, sizeof(int), asc);
    unsigned long long int ans = 0;
    for (i = 1; i < 2 * n; i += 2)
        ans += (unsigned long long int)a[i];
    printf("%lld\n", ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &n);
     ^
./Main.c:14:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d", &a[i]);
         ^