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

#define N_MAX 2000
#define M_MAX 200000

ull n, m;

ull a[N_MAX];
ull b[N_MAX];

bool isreached[100][100];
bool isreachable[100][100];

void set1nize (ull v, bool *array[]) {
	sll i, j, ki;

	for (i = 0; i < n; i++) {
		for (j = 0; j < v; j++) {
			for (ki = j; ki <= 50; ki += v) {
				if (array[i][ki]) {
					array[i][j] = true;
					break;
				}
			}
		}

		// (j-k loop) =~ 50
	}

	return;
}

bool is0able (ull v) {
	sll i, j;

	bool *isreachable_ARG[100];
	for (i = 0; i < n; i++) {
		isreachable_ARG[i] = isreachable[i];

		for (j = 0; j <= 50; j++) {
			isreachable[i][j] = isreached[i][j];
		}
	}

	while (--v) {
		set1nize(v, isreachable_ARG);
	}

	for (i = 0; i < n; i++) {
		if (!isreachable[i][b[i]]) return false;
	}
	return true;
}

ull solve () {
	sll i, j, ki;
	// ull result = 0;
	sll result = 0;
	// double result = 0;
	// ull maybe = 0;
	sll maybe = 0;
	// ull sum = 0;
	sll sum = 0;
	ull item;
	ull *dpcell;

	bool *isreached_ARG[100];
	for (i = 0; i < n; i++) {
		isreached_ARG[i] = isreached[i];
	}

	for (i = 0; i < n; i++) {
		for (j = 0; j <= 50; j++) {
			isreached[i][j] = false;
		}
		isreached[i][a[i]] = true;
	}

	if (!is0able(51)) goto fail;

	result = 0;
	for (i = 50; i >= 1; i--) {
		if (!is0able(i)) {
			result |= (1ULL << i);
			set1nize(i, isreached_ARG);
		}
	}

	printf("%llu\n", result);

	return 0;

	fail:
	puts("-1");
	return 1;
}

int32_t main (void) {
	int32_t i, j;
	int32_t x, y;

	scanf("%llu", &n);
	for (i = 0; i < n; i++) {
		scanf("%llu", &a[i]);
	}
	for (i = 0; i < n; i++) {
		scanf("%llu", &b[i]);
	}
	solve();

	return 0;
} ./Main.c: In function ‘solve’:
./Main.c:105:9: warning: format ‘%llu’ expects argument of type ‘long long unsigned int’, but argument 2 has type ‘sll {aka long int}’ [-Wformat=]
  printf("%llu\n", result);
         ^
./Main.c: In function ‘main’:
./Main.c:118:8: warning: format ‘%llu’ expects argument of type ‘long long unsigned int *’, but argument 2 has type ‘ull * {aka long unsigned int *}’ [-Wformat=]
  scanf("%llu", &n);
        ^
./Main.c:120:9: warning: format ‘%llu’ expects argument of type ‘long long unsigned int *’, but argument 2 has type ‘ull * {aka long unsigned int *}’ [-Wformat=]
   scanf("%llu", &a[i]);
         ^
./Main.c:123:9: warning: format ‘%llu’ expects argument of type ‘long long unsigned int *’, but argument 2 has type ‘ull * {aka long unsigned int *}’ [-Wformat=]
   scanf("%llu", &b[i]);
         ^
./Main.c:118:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%llu", &n);
  ^
./Main.c:120:3: warning: ignoring retu...