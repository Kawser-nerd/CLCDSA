#include <stdio.h>
int main() {
    long long A, B, C, K;
    scanf("%lld %lld %lld %lld", &A, &B, &C, &K);
    printf("%lld\n", (K%2)?(B-A):(A-B));
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld %lld %lld %lld", &A, &B, &C, &K);
     ^