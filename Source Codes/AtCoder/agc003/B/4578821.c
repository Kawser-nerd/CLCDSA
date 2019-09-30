#include<stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    int i;
    int a;
    unsigned long long int ans = 0;
    int x = 0;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a);
        if (a == 0)
            x = 0;
        else
        {
            if (x == 1)
            {
                ans++;
                a--;
                x = 0;
            }
            ans += (unsigned long long int)a / 2;
            x = a % 2;
        }
    }
    printf("%lld\n", ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &n);
     ^
./Main.c:12:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d", &a);
         ^