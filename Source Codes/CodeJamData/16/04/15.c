
#include <stdio.h>

int main() {
    int cases;
    scanf("%d\n", &cases);
    for (int n = 1; n <= cases; ++n) {
        long long k, c, s;
        scanf("%lld %lld %lld\n", &k, &c, &s);
        long long required = (k - 1) / c + 1;
        printf("Case #%d: ", n);
        if (required > s)
            printf("IMPOSSIBLE");
        else {
            long long current = 0;
            for (long long i = 0; i < required; ++i) {
                long long index = 1;
                long long pow = 1;
                for (long long j = 0; j < c; ++j) {
                    index += pow * current;
                    pow *= k;
                    if (current < k - 1)
                        ++current;
                }
                printf("%lld ", index);
            }
        }
        printf("\n");
    }
    return 0;
}
