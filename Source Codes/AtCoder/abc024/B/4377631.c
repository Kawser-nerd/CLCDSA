#include <stdio.h>
#define min(a, b) a < b ? a : b
int main(void)
{
    int n, t;
    scanf("%d%d", &n, &t);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    int dif[n - 1];
    for (int i = 0; i < n - 1; i++)
    {
        dif[i] = a[i + 1] - a[i];
    }
    int ans = 0;
    for (int i = 0; i < n - 1; i++)
    {
        ans += min(dif[i], t);
    }
    printf("%d\n", ans + t);
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d", &n, &t);
     ^
./Main.c:10:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d", &a[i]);
         ^