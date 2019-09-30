#include<stdio.h>
int main()
{
    int n, a, b;
    scanf("%d %d %d", &n, &a, &b);
    int ans;
    if (n <= 5)
        ans = b * n;
    else
        ans = 5 * b + (n - 5)*a;
    printf("%d\n", ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d %d", &n, &a, &b);
     ^