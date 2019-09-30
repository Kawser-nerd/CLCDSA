#include<stdio.h>

int main()
{
    int x, a, b;
    scanf("%d %d %d",&x, &a, &b);
    x = x - a;
    printf("%d\n",x % b);

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d %d",&x, &a, &b);
     ^