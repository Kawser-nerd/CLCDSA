#include<stdio.h>
int main()
{
    double n, k;
    scanf("%lf %lf", &n, &k);
    double ans;
    ans = (1 + ((n - 1) * 3) + (6 * (k - 1)*(n - k)));
    ans /= (n*n*n);
    printf("%.20lf\n", ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lf %lf", &n, &k);
     ^