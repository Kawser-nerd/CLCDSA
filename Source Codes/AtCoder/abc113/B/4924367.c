#include <stdio.h>
#include <math.h>

int main()
{
    double t, a;
    int n, k;
    scanf("%d%lf%lf", &n, &t, &a);
    int h[n];
    double min = 10000000;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &h[i]);
        if (min > fabs((t - h[i] * 0.006) - a))
        {
            min = fabs((t - h[i] * 0.006) - a);
            k = i;
        }
    }
    printf("%d\n", k + 1);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%lf%lf", &n, &t, &a);
     ^
./Main.c:13:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d", &h[i]);
         ^