/*
cat <<EOF >mistaken-paste
*/

#pragma GCC diagnostic ignored "-Wincompatible-pointer-types"
#define _USE_MATH_DEFINES

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

#define BIG 2000000007
#define VERYBIG 200000000000007LL

#define MOD 1000000007
#define FOD  998244353
typedef uint64_t ull;
typedef  int64_t sll;

#define N_MAX 200000
#define M_MAX 200000


ull n, m;

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


sll a[N_MAX];
sll b[N_MAX];

char s[N_MAX + 1];


ull dp[N_MAX + 1][3][3];

ull solve () {
	sll i, j, ki, li;
	// ull result = 0;
	sll result = 0;
	double dresult = 0;
	// ull maybe = 0;
	sll maybe = 0;
	// ull sum = 0;
	sll sum = 0;
	sll item;
	ull *dpcell;

	n = strlen(s);
	if (n == 3) {
		if (s[0] == s[2]) {
			if (s[0] == s[1]) {
				result = 1;
			} else {
				result = 7;
			}
		} else {
			if (s[0] == s[1] || s[1] == s[2]) {
				result = 6;
			} else {
				result = 3;
			}
		}
		goto success;
	}

	bool ndiff = true;
	bool nsame = true;
	for (i = 0; i < n; i++) {
		if (i && s[i - 1] != s[i]) ndiff = false;
		if (i && s[i - 1] == s[i]) nsame = false;

		sum = (sum + (s[i] - 'a')) % 3;
	}
	if (ndiff) {
		result = 1;
		goto success;
	}

	for (i = 0; i < n; i++) { // length
		for (j = 0; j < 3; j++) { // sum
			for (ki = 0; ki < 3; ki++) { // last
				if (i == 0) {
					dp[i][j][ki] = (j == ki ? 1 : 0);
					continue;
				}
				ull befs = (3 + j - ki) % 3;

				dp[i][j][ki] = dp[i - 1][befs][(ki + 1) % 3] + dp[i - 1][befs][(ki + 2) % 3];
				dp[i][j][ki] %= FOD;
			}
		}
	}

	result = (nsame ? (FOD - 1) : 0);
	for (ki = 0; ki < 3; ki++) {
		result += dp[n - 1][sum][ki];
		result %= FOD;
	}
	result = (FOD + bitpow(3, n - 1, FOD) - result) % FOD;

	printf("%lld\n", result);

	return 0;

	success:
	printf("%llu\n", result);
	return 0;
}

int32_t main (void) {
	scanf("%s", s);

	solve();

	return 0;
} ./Main.c: In function ‘solve’:
./Main.c:117:9: warning: format ‘%lld’ expects argument of type ‘long long int’, but argument 2 has type ‘sll {aka long int}’ [-Wformat=]
  printf("%lld\n", result);
         ^
./Main.c:122:9: warning: format ‘%llu’ expects argument of type ‘long long unsigned int’, but argument 2 has type ‘sll {aka long int}’ [-Wformat=]
  printf("%llu\n", result);
         ^
./Main.c: In function ‘main’:
./Main.c:127:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s", s);
  ^