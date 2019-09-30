#include<stdio.h>
int main()
{
    double n;
    scanf("%lf", &n);
    n *= 9;
    n /= 5;
    n += 32;
    printf("%.20lf\n", n);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lf", &n);
     ^