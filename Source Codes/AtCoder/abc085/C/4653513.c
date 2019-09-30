#include <stdio.h>

int main()
{
    long long n, y;
    long long yukichi, higuchi, hideyo;

    scanf("%lld %lld", &n, &y);

    for (hideyo = 0; hideyo <= n; hideyo++) {
        for (higuchi = 0; higuchi <= n; higuchi++) {
            yukichi = n - (hideyo + higuchi);

            if (0 <= yukichi && 0 <= higuchi && 0 <= hideyo &&
                yukichi * 10000 + higuchi * 5000 + hideyo * 1000 == y) {
                printf("%lld %lld %lld\n", yukichi, higuchi, hideyo);
                return 0;
            }
        }
    }

    printf("-1 -1 -1\n");

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld %lld", &n, &y);
     ^