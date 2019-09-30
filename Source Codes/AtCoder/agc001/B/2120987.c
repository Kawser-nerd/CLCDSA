#include<stdio.h>
#include<stdlib.h>

unsigned long long N, X, a, b, t, r, ans;

int main() {
	scanf("%llu %llu", &N, &X);
    ans += N;
    a = X, b = N - X;
    while (1) {
        t = 2 * (a / b);
        r = a%b;
        ans += b*t;
        if (r == 0) {
            ans -= b;
            break;
        }
        a = b;
        b = r;
    }
    printf("%llu\n",ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%llu %llu", &N, &X);
  ^