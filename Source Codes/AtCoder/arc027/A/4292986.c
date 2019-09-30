#include<stdio.h>
int main()
{
    int h, m;
    scanf("%d %d", &h, &m);
    printf("%d\n", 60 * 18 - 60 * h - m);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d", &h, &m);
     ^