#include<stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    int i, j, k;
    int a[55];
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    int ans = -200000000;
    int aoki, takahashi, ao, taka;
    int s, t;
    for (i = 0; i < n; i++)
    {
        aoki = takahashi = -20000000;
        for (j = 0; j < n; j++)
        {
            if (i != j)
            {
                ao = taka = 0;
                if (j < i)
                {
                    s = j;
                    t = i;
                }
                else
                {
                    s = i;
                    t = j;
                }
                for (k = s; k <= t; k++)
                {
                    if ((k - s) % 2 == 0)
                        taka += a[k];
                    else
                        ao += a[k];
                }
                if (aoki < ao)
                {
                    aoki = ao;
                    takahashi = taka;
                }
            }
        }
        if (ans < takahashi)
            ans = takahashi;
    }
    printf("%d\n", ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &n);
     ^
./Main.c:9:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d", &a[i]);
         ^