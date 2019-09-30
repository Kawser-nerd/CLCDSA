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

#define N_MAX 300000
#define M_MAX 200000

ull n, m;

ull umin (ull x, ull y) {
	return (x < y) ? x : y;
}


sll a[N_MAX];
sll b[N_MAX];
sll c[N_MAX];
// char s[N_MAX];
char s[3010][3010];

ull dp[N_MAX + 1];

ull nibu (ull x, ull l) {
	ull ok = 0, ng = l + 1;
	while (ok + 1 < ng) {
		ull med = (ok + ng) / 2;
		if (dp[med] <= x) {
			ok = med;
		} else {
			ng = med;
		}
	}

	return ng;
}

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

	ull lis = 0;
	dp[0] = 0;
	for (i = 0; i < n; i++) {
		ull leq = nibu(a[i], lis);
		
		if (leq > lis) {
			lis++;
			dp[leq] = a[i];
		}
		dp[leq] = umin(dp[leq], a[i]);
		// printf("[%llu] %llu\n", leq, dp[leq]);
	}

	result = n - lis;

	printf("%lld\n", result);
	return 0;
}

int32_t main (void) {
	int32_t i, j;
	int32_t x, y;

	scanf("%llu", &n, &m);
	for (i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
	}
	solve();

	return 0;
} ./Main.c: In function ‘solve’:
./Main.c:83:9: warning: format ‘%lld’ expects argument of type ‘long long int’, but argument 2 has type ‘sll {aka long int}’ [-Wformat=]
  printf("%lld\n", result);
         ^
./Main.c: In function ‘main’:
./Main.c:91:8: warning: format ‘%llu’ expects argument of type ‘long long unsigned int *’, but argument 2 has type ‘ull * {aka long unsigned int *}’ [-Wformat=]
  scanf("%llu", &n, &m);
        ^
./Main.c:91:8: warning: too many arguments for format [-Wformat-extra-args]
./Main.c:93:9: warning: format ‘%lld’ expects argument of type ‘long long int *’, but argument 2 has type ‘sll * {aka long int *}’ [-Wformat=]
   scanf("%lld", &a[i]);
         ^
./Main.c:91:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%llu", &n, &m);
  ^
./Main.c:93:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld", &a[i]);
   ^