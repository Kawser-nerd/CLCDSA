#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    double a, b;
    scanf("%lf%lf", &a, &b);
    printf("%.0f\n", round((a + b) / 2));

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lf%lf", &a, &b);
     ^