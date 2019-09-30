#include <stdio.h>
typedef long long unsigned int u64;
u64 min(const u64 a, const u64 b) {
    return a < b ? a : b;
}
u64 max(const u64 a, const u64 b) {
    return a > b ? a : b;
}
u64 numdigits(u64 n) { 
    int i;
    for(i = 0; n != 0; n /= 10, i++);
    return i;
}
u64 f(u64 a, u64 b) {
    return max(numdigits(a), numdigits(b));
}
u64 solve(u64 n) {
    u64 minf = 4000;
    for(u64 i = 1; i * i <= n; i++) {
        if(n % i == 0) {
            u64 a = i;
            u64 b = n / i;
            minf = min(minf, f(a, b));
        }
    }
    return minf;
}
int main(void) {
    u64 n;
    scanf("%llu", &n);
    printf("%llu", solve(n));
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:30:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%llu", &n);
     ^