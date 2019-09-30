#include<stdio.h>
#include<math.h>
int main()
{
    double n, va, vb, l;
    scanf("%lf %lf %lf %lf", &n, &va, &vb, &l);
    printf("%.20lf\n", pow(vb / va, n)*l);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lf %lf %lf %lf", &n, &va, &vb, &l);
     ^