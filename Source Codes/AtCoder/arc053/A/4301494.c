#include<stdio.h>
int main()
{
    int h, w;
    scanf("%d %d", &h, &w);
    printf("%d\n", w*(h - 1) + h * (w - 1));
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d", &h, &w);
     ^