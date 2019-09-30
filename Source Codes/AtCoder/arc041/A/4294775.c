#include<stdio.h>
int main()
{
    int x, y, k;
    scanf("%d %d%d", &x, &y, &k);
    if (k <= y)
        printf("%d\n", x + k);
    else
        printf("%d\n", x + y - k + y);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d%d", &x, &y, &k);
     ^