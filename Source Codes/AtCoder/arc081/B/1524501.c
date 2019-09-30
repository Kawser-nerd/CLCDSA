#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define BIG 2000000007

#define MOD 1000000007
typedef unsigned long long ull;
typedef   signed long long sll;

typedef struct {
	ull above;
	ull below;
	int index;
} hw;

#define N_MAX 52
#define M_MAX 100000

ull n, m, k;
ull h, w;
// ull a[N_MAX];
// ull b[N_MAX];
// ull dp[N_MAX][M_MAX + 1];
char s[N_MAX + 1];

void swap_adj(ull *a, ull *b){
	ull tmp = *b;
	*b = *a;
	*a = tmp;
	return;
}

int comp(const void *a, const void *b){
	if (*(ull*)a > *(ull*)b) {
		return -1;
	} else if (*(ull*)a < *(ull*)b) {
		return +1;
	} else {
		return 0;
	}
}

ull divide(ull a, ull b){
	ull x = MOD - 2;
	ull ans = 1;
	while (x) {
		if (x & 1) ans = (ans * b) % MOD;
		b = (b * b) % MOD;
		x /= 2;
	}
	return (a * ans) % MOD;
}

int digits(ull x){
	int i = 1;
	while (x >= 10) {
		x /= 10;
		i++;
	}
	return i;
}

int min(ull x, ull y){
	return (x < y) ? x : y;
}

ull gcd(ull x, ull y){
	if (x < y) {
		return gcd(y, x);
	} else if (y == 0) {
		return x;
	} else {
		return gcd(y, x % y);
	}
}

ull bitpow(ull a, ull x){
	ull result = 1;
	while (x) {
		if (x & 1) {
			result *= a;
			result %= MOD;
		}
		x /= 2;
		a = (a * a) % MOD;
	}
	return result;
}

ull solve(){
	int i, j;
	ull mul2 = 0, mul3 = 0;
	int prev = 0;

	i = 0;
	while (i < n) {
		if (i + 1 < n && s[i] == s[i + 1]) {
			switch (prev) {
			case 0:
				mul2 = 1;
				mul3 = 1;
				break;
			case 1:
				mul2++;
				break;
			case 2:
				mul3++;
				break;
			}
			prev = 2;
			i += 2;
		} else {
			switch (prev) {
			case 0:
				mul3 = 1;
				break;
			case 1:
				mul2++;
				break;
			case 2:
				//
				break;
			}
			prev = 1;
			i++;
		}
	}

	printf("%llu\n", bitpow(2, mul2) * bitpow(3, mul3) % MOD);

	return 0;
}

int main(void){
	int i, j;

	scanf("%llu", &n);
	scanf("%s", s);
	scanf("%*s");

	solve();

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:139:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%llu", &n);
  ^
./Main.c:140:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s", s);
  ^
./Main.c:141:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%*s");
  ^