#include<stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    int i;
    int a[102];
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    int ans = 0;
    int x;
    int j;
    for (j = 0; j < 8; j++)
    {
        x = 0;
        for (i = 0; i < n; i++)
        {
            if (a[i] >= 400 * j && a[i] < 400 * (j + 1))
                x++;
        }
        if (x > 0)
            ans++;
    }
    x = 0;
    for (i = 0; i < n; i++)
        if (a[i] >= 3200)
            x++;
    if (ans == 0)
        printf("1 ");
    else
        printf("%d ", ans);
    ans += x;
    printf("%d\n", ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &n);
     ^
./Main.c:9:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d", &a[i]);
         ^