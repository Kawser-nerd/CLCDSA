#include <stdio.h>
double n;
int main()
{
    scanf("%lf",&n);
    return printf("%.10f\n",9.0/5.0*n+32.0)&0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lf",&n);
     ^