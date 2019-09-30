#include<stdio.h>

int main(void)
{
    int t, x;
    double a;

    scanf("%d%d", &t, &x);

    a = (double)t / (double)x;

    printf("%lf", a);

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d", &t, &x);
     ^