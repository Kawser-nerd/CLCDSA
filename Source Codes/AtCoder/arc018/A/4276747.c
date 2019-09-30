#include<stdio.h>
int main()
{
    double h, b;
    scanf("%lf %lf", &h, &b);
    h /= 100;
    printf("%.20lf\n", b*h*h);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lf %lf", &h, &b);
     ^