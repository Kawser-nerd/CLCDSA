#include<stdio.h>
int main()
{
    int a, b, c, d, e;
    scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
    if (a + d + e > b + c + e)
        printf("%d\n", a + d + e);
    else
        printf("%d\n", b + c + e);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
     ^