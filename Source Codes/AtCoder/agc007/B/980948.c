#include <stdio.h>
#include <stdint.h>

#define MAX_N (20000)
int main(void)
{
    uint32_t i, N, a[MAX_N], b[MAX_N], p[MAX_N];
    uint32_t stride;
    scanf("%u", &N);
    stride = N;
    for (i = 0; i < N; i++) {
        uint32_t val;
        scanf("%u", &val);
        p[i] = val - 1;
    }
    for (i = 0; i < N; i++) {
        a[i] = (i * stride) + 1;
        b[i] = ((N - 1 - i) * stride) + 1;
    }
    for (i = 0; i < N; i++) {
        const uint32_t idx = p[i];
        a[idx] += i;
    }
    for (i = 0; i < N; i++) {
        printf("%u ", a[i]);
    }
    putchar('\n');
    for (i = 0; i < N; i++) {
        printf("%u ", b[i]);
    }
    putchar('\n');
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%u", &N);
     ^
./Main.c:13:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%u", &val);
         ^