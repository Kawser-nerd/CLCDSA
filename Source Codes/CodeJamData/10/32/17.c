#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[])
{
    int tt;
    scanf("%d", &tt);
    int i;
    for (i = 0; i < tt; ++i)
    {
        int l, p, c;
        scanf("%d%d%d", &l, &p, &c);
        long double dl, dp, dc, dt;
        dl = l;
        dp = p;
        dc = c;
        dt = log10(dp / dl) / log10(c);
        dt = ceil(dt);
        long res;
        res = (long) ceil(log10(dt) / log10(2.00));
        printf("Case #%d: %ld\n", i + 1, res);
    }
    return 0;
}
