#include<stdio.h>
#include<math.h>
int min(int a, int b)
{
    if (a < b)
        return a;
    else
        return b;
}
int main()
{
    int n;
    scanf("%d", &n);
    int i;
    int a[100005];
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    int ans[100005];
    for (i = 0; i < 100005; i++)
        ans[i] = 2000000000;
    ans[0] = 0;
    for (i = 0; i < n; i++)
    {
        ans[i + 1] = min(ans[i + 1], ans[i] + abs(a[i] - a[i + 1]));
        ans[i + 2] = min(ans[i + 2], ans[i] + abs(a[i] - a[i + 2]));
    }
    printf("%d\n", ans[n - 1]);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:24:47: warning: implicit declaration of function ‘abs’ [-Wimplicit-function-declaration]
         ans[i + 1] = min(ans[i + 1], ans[i] + abs(a[i] - a[i + 1]));
                                               ^
./Main.c:13:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &n);
     ^
./Main.c:17:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d", &a[i]);
         ^