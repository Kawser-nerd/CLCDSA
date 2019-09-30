#include <stdio.h>

int main()
{
    int cn, cc;

    freopen("B-large.in", "r", stdin);
    freopen("b.out", "w", stdout);

    scanf("%d", &cn);

    for (cc=1; cc<=cn; cc++)
    {
        int i;
        double c, f, x, n;
        double sum;

        scanf("%lf%lf%lf", &c, &f, &x);
        n = x / c - 2.0 / f;

        sum = 0.0;
        for (i=0; i+1 < n + 1e-9; i++)
            sum += c / ( 2.0 + f * i);
        sum += x / ( 2.0 + f * i);

        printf("Case #%d: %.7f\n", cc, sum);
    }

    return 0;
}
