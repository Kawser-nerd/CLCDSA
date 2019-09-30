#include <stdio.h>

int mod = 1000000007;

int main() {
    unsigned long long int a, b, c, ans;

    scanf("%llu %llu %llu", &a, &b, &c);

    ans = (((a * b) % mod) * c) % mod;
    printf("%llu\n", ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%llu %llu %llu", &a, &b, &c);
     ^