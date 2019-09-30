#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    if (*(double *)a - *(double *)b < 0)
        return -1;
    else 
        return 1;
}

int opt(double *adv, double *dadv, int n);

int main()
{
    int cn, cc;

    freopen("D-large.in", "r", stdin);
    freopen("d.out", "w", stdout);

    scanf("%d", &cn);

    for (cc=1; cc<=cn; cc++)
    {
        double nao[1000], ken[1000];
        int n;
        int i;

        scanf("%d", &n);
        for (i=0; i<n; i++)
            scanf("%lf", nao+i);
        for (i=0; i<n; i++)
            scanf("%lf", ken+i);

        qsort(nao, n, sizeof(double), cmp);
        qsort(ken, n, sizeof(double), cmp);

        printf("Case #%d: %d %d\n", cc, opt(nao, ken, n), n - opt(ken, nao, n));
    }

    return 0;
}

int opt(double *adv, double *dadv, int n)
{
    int cnt = 0;
    int a = 0, b = 0;

    while (a < n && b < n)
    {
        while (a < n && adv[a] < dadv[b])
            a++;
        if (a >= n) break;
        cnt++;
        a++;
        b++;
    }

    return cnt;
}
