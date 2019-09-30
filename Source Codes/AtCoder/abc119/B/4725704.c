#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int n;
    scanf("%d", &n);
    double x[n];
    char u[n][3];
    int i;
    double ans = 0;
    for (i = 0; i < n; i++)
    {
        scanf("%lf%s", &x[i], u[i]);
    }
    for (i = 0; i < n; i++)
    {
        if (u[i][0] == 'J')
        {
            ans += x[i];
        }
        else
        {
            ans += x[i] * 380000;
        }
    }
    printf("%lf\n", ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &n);
     ^
./Main.c:15:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%lf%s", &x[i], u[i]);
         ^