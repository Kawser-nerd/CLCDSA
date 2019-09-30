#include <stdio.h>
int main()
{
    double a, b, d, e;
    int c;
    scanf("%lf%lf", &a, &b);
    e = (a + b) / 2;
    c = (a + b) / 2;
    d = e - c;

    if (d >= 0.5)
    {
        c = c + 1;
        printf("%d", c);
    }
    else
    {
        printf("%d", c);
    }
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lf%lf", &a, &b);
     ^