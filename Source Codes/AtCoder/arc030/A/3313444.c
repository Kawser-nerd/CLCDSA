#include <stdio.h>

int main()
{
    int n, k;
    scanf("%d", &n);
    scanf("%d", &k);
    if (n / 2 >= k) puts("YES");
    else puts("NO");
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &n);
     ^
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &k);
     ^