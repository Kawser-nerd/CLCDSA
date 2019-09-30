#include<stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    double ans = 0;
    double a, b, c, d, e;
    int i;
    for (i = 0; i < n; i++)
    {
        scanf("%lf %lf %lf %lf %lf", &a, &b, &c, &d, &e);
        if (ans < a + b + c + d + e * 11 / 90)
            ans = a + b + c + d + e * 11 / 90;
    }
    printf("%.20lf\n", ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &n);
     ^
./Main.c:11:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%lf %lf %lf %lf %lf", &a, &b, &c, &d, &e);
         ^