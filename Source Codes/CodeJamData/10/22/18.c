#include <stdio.h>

uint64_t X[70];
uint64_t V[70];

int main ()
{
    uint64_t N, K, B, T, C;
    int i, j;
    int cool_chicks, slow_chicks;
    int swaps;

    scanf("%llu", &C);

    for (i=0; i<C; i++) {
        scanf("%llu %llu %llu %llu", &N, &K, &B, &T);

        for (j=0; j<N; j++) {
            scanf("%llu", &X[j]);
        }
        for (j=0; j<N; j++) {
            scanf("%llu", &V[j]);
        }

        cool_chicks = slow_chicks = 0;
        swaps = 0;
        for (j=N-1; j>=0; j--) {
            if (T*V[j]+X[j] >= B) {
                if (slow_chicks) {
                    swaps += slow_chicks;
                }
                cool_chicks++;
            } else {
                slow_chicks++;
            }
            if (cool_chicks >= K)
                break;
        }
        if (cool_chicks < K)
            printf("Case #%d: IMPOSSIBLE\n", i+1);
        else 
            printf("Case #%d: %d\n", i+1, swaps);
    }
}
