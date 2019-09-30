#include<stdio.h>
int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    int a1, a2;
    int ans = 0;
    int i;
    scanf("%d", &a1);
    int x = 1;
    for (i = 1; i < n; i++)
    {
        scanf("%d", &a2);
        if (a2 > a1)
            x++;
        else
        {
            if (x >= k)
                ans += x - k + 1;
            x = 1;
        }
        a1 = a2;
    }
    if (x >= k)
        ans += x - k + 1;
    printf("%d\n", ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d", &n, &k);
     ^
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &a1);
     ^
./Main.c:13:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d", &a2);
         ^