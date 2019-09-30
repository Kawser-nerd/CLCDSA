#include<stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    int i, j;
    int c[502], s[502], f[502];
    for (i = 0; i < n - 1; i++)
        scanf("%d %d %d", &c[i], &s[i], &f[i]);
    int ans;
    for (i = 0; i < n; i++)
    {
        ans = 0;
        for (j = i; j < n - 1; j++)
        {
            if (ans < s[j])
                ans = s[j];
            else if (ans%f[j] > 0)
                ans = ans - (ans%f[j]) + f[j];
            ans += c[j];
        }
        printf("%d\n", ans);
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &n);
     ^
./Main.c:9:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d %d %d", &c[i], &s[i], &f[i]);
         ^