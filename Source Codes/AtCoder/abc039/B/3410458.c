#include<stdio.h>
int main()
{
    int x;
    scanf("%d", &x);
    int ans = 0;
    while (ans*ans*ans*ans < x)
        ans++;
    printf("%d\n", ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &x);
     ^