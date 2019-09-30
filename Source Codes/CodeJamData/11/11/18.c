#include <stdio.h>

typedef unsigned long long ull;

int main()
{
    ull t, i;
    scanf("%llu", &t);

    for(i = 0; i < t; i++) {
        ull n, pd, pg;
        scanf("%llu%llu%llu", &n, &pd, &pg);
        if (pg == 0 && pd > 0 || pg == 100 && pd < 100) {
            printf("Case #%llu: Broken\n", i + 1);
        } else {
            ull lim = n;
            ull j;
            if (lim > 100) lim = 100;
            for (j = 1; j <= lim; j++)
                if (j * pd % 100 == 0) {
                   printf("Case #%llu: Possible\n", i + 1);
                   break;
                }

            if (j > lim)
                printf("Case #%llu: Broken\n", i + 1);
            
        }
    }
    return 0;
}
