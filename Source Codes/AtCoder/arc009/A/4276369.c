#include<stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    int ans = 0;
    int a, b, i;
    for (i = 0; i < n; i++)
    {
        scanf("%d %d", &a, &b);
        ans += a * b;
    }
    ans = (int)(ans*1.05);
    printf("%d\n", ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &n);
     ^
./Main.c:10:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d %d", &a, &b);
         ^