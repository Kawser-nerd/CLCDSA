#include <stdio.h>
#define MOD 1000000007
typedef unsigned long long ull;
typedef   signed long long sll;
ull n;
ull k;
ull bitpow (ull a, ull x, ull modulo) {
	ull result = 1;
	while (x) {
		if (x & 1) {
			result *= a;
			result %= modulo;
		}
		x /= 2;
		a = (a * a) % modulo;
	}
	return result;
}
ull divide (ull a, ull b, ull modulo) {
	return (a * bitpow(b, modulo - 2, modulo)) % modulo;
}
ull solve () {
	ull up = 1, down = 1;
	for (sll i = 1; i <= k; i++) {
		up = (up * (k + n - i)) % MOD;
		down = (down * i) % MOD;
	}
	printf("%llu\n", divide(up, down, MOD));
	return 0;
}

int main (void) {
	scanf("%llu%llu", &n, &k);
	solve();
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:33:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%llu%llu", &n, &k);
  ^