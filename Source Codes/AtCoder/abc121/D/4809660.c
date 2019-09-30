#include <stdio.h>

typedef long long int ll;

ll solve(ll n) {
    switch(n % 4) {
        case 0: return n; break;
        case 1: return 1; break;
        case 2: return n+1; break;
        case 3: return 0; break;
    }
}

int main() {
    ll a, b;
    scanf("%lld %lld", &a, &b);
    printf("%lld\n", solve(a-1)^solve(b));
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:16:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld %lld", &a, &b);
     ^