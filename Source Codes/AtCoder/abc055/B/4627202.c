#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long int ans;
long long int MOD = 1000000007;

long long int fact(int n) {
    long long int res = 1;
    for (int i = 1; i <= n; i++) {
        res *= i;
        res %= MOD;
    }
    return res;
}

int main(void) {
    int n;
    scanf("%d", &n);

    printf("%lld\n", fact(n));
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:21:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &n);
     ^