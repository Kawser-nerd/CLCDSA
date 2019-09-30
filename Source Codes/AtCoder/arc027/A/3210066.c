#include <stdio.h>
int h, m;
int main()
{
    scanf("%d %d", &h, &m);
    printf("%d\n", 1080 - h * 60 - m);
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d", &h, &m);
     ^