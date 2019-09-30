#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

int main()
{
    long long int T, t, K, C, S, i, actual, j;
    scanf("%" PRId64, &T);
    for (t=1; t<=T; t++) {
        scanf("%lld", &K);
        scanf("%lld", &C);
        scanf("%lld", &S);
        if ((C*S)<K) {
            printf("Case #%lld: IMPOSSIBLE\n", t);
            continue;
        }
        printf("Case #%lld:", t);
        i=0;
        while (i<K) {
            actual = 0;
            for (j=0;j<C;j++) {
                actual*=K;
                actual+=(i%K);
                i++;
            }
            printf(" %lld", actual + 1);
        }
        printf("\n");
    }
    return 0;
}
