#include<stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    int i;
    int l[202];
    for (i = 0; i < 2 * n; i++)
        scanf("%d", &l[i]);
    int x;
    for (i = 0; i < 2 * n - 1; i++)
    {
        if (l[i] < l[i + 1])
        {
            x = l[i];
            l[i] = l[i + 1];
            l[i + 1] = x;
            if (i > 0)
                i -= 2;
        }
    }
    int ans = 0;
    for (i = 1; i < 2 * n; i += 2)
        ans += l[i];
    printf("%d\n", ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &n);
     ^
./Main.c:9:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d", &l[i]);
         ^