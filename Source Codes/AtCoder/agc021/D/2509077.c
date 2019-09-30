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
typedef uint64_t ull;
typedef  int64_t sll;

#define N_MAX 200000
#define M_MAX 200000

typedef struct {
	int32_t a;
	int32_t b;
} hw;

typedef struct {
	sll a;
	sll b;
} hwll;

typedef struct {
	hwll a;
	hwll b;
} linell;


typedef struct {
	ull s;
	ull t;
	int32_t c;
} struct_a;

typedef struct {
	int32_t from;
	int32_t to;
	sll cost;
} struct_b;

ull n, m;
ull h, w;
ull k;
ull q;
ull vua, vub, vuc, vud, vue, vuf;
sll vsa, vsb, vsc, vsd, vse, vsf;
long double vra, vrb, vrc;
double vda, vdb, vdc;
size_t slen;
size_t tlen;
char ch, dh;

ull umax (ull x, ull y) {
	return (x > y) ? x : y;
}

char s[401];

ull dp[305][305][305];

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
	for (j = 0; j <= n; j++) {
		for (i = 0; i + j <= n; i++) {
			for (ki = 0; ki <= k; ki++) {
				if (j == 0) {
					dp[i][j][ki] = 0;
					continue;
				}
				if (j == 1) {
					dp[i][j][ki] = 1;
					continue;
				}

				bool isaddable = (s[i] == s[i + j - 1]);
				maybe = umax(umax(dp[i][j - 1][ki], dp[i + 1][j - 1][ki]), dp[i + 1][j - 2][ki] + (isaddable ? 2 : 0));
				if (!isaddable && ki) {
					maybe = umax(maybe, dp[i + 1][j - 2][ki - 1] + 2);
				}

				dp[i][j][ki] = maybe;
				// printf("%lld/%lld/%lld: %lld\n", i, j, ki, maybe);
			}
		}
	}

	result = 0;
	for (ki = 0; ki <= k; ki++) {
		result = umax(result, dp[0][n][ki]);
	}

	printf("%lld\n", result);

	return 0;
}

int32_t main (void) {
	int32_t i, j;
	int32_t x, y;

	scanf("%s", s);
	scanf("%llu", &k);

	solve();

	return 0;
} ./Main.c: In function ‘solve’:
./Main.c:116:9: warning: format ‘%lld’ expects argument of type ‘long long int’, but argument 2 has type ‘sll {aka long int}’ [-Wformat=]
  printf("%lld\n", result);
         ^
./Main.c: In function ‘main’:
./Main.c:126:8: warning: format ‘%llu’ expects argument of type ‘long long unsigned int *’, but argument 2 has type ‘ull * {aka long unsigned int *}’ [-Wformat=]
  scanf("%llu", &k);
        ^
./Main.c:125:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s", s);
  ^
./Main.c:126:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%llu", &k);
  ^