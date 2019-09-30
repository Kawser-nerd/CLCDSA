#include <stdio.h>
int main()
{
    int a;
    scanf("%d", &a);
    printf((a == 3 || a == 5 || a == 7) ? "YES" : "NO");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &a);
     ^