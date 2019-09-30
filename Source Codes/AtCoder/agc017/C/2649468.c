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

typedef uint64_t ull;
typedef  int64_t sll;

#define N_MAX 300000
#define M_MAX 200000

ull n, m;
ull q;


sll smax (sll x, sll y) {
	return (x > y) ? x : y;
}


sll a[N_MAX];
sll cover[N_MAX + 1];
ull num[N_MAX + 1];

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

	for (i = 0; i < n; i++) {
		num[a[i]]++;
	}
	for (i = 1; i <= n; i++) {
		sll end = i + 1;
		sll begin = end - num[i];

		cover[smax(begin, 1)]++;
		cover[end]--;
	}
	for (i = 1; i <= n; i++) {
		sum += cover[i];
		cover[i] = sum;

		if (cover[i] > 0) result++;
	}

	while (q--) {
		sll x, y;
		scanf("%lld%lld", &x, &y);
		ull prev = a[x - 1];
		a[x - 1] = y;


		sll pleft = prev - --num[prev];
		if (pleft > 0 && --cover[pleft] == 0) {
			result--;
		}

		sll pright = y - num[y]++;
		if (pright > 0 && ++cover[pright] == 1) {
			result++;
		}

		printf("%llu\n", n - result);
	}

	return 0;
}

int32_t main (void) {
	int32_t i, j;
	int32_t x, y;

	scanf("%llu", &n, &m);
	scanf("%llu", &q);
	for (i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
	}

	solve();

	return 0;
} ./Main.c: In function ‘solve’:
./Main.c:66:9: warning: format ‘%lld’ expects argument of type ‘long long int *’, but argument 2 has type ‘sll * {aka long int *}’ [-Wformat=]
   scanf("%lld%lld", &x, &y);
         ^
./Main.c:66:9: warning: format ‘%lld’ expects argument of type ‘long long int *’, but argument 3 has type ‘sll * {aka long int *}’ [-Wformat=]
./Main.c:81:10: warning: format ‘%llu’ expects argument of type ‘long long unsigned int’, but argument 2 has type ‘long unsigned int’ [-Wformat=]
   printf("%llu\n", n - result);
          ^
./Main.c: In function ‘main’:
./Main.c:91:8: warning: format ‘%llu’ expects argument of type ‘long long unsigned int *’, but argument 2 has type ‘ull * {aka long unsigned int *}’ [-Wformat=]
  scanf("%llu", &n, &m);
        ^
./Main.c:91:8: warning: too many arguments for format [-Wformat-extra-args]
./Main.c:92:8: warning: format ‘%llu’ expects argument of type ‘long long unsigned int *’, but argument 2 has type ‘ull * {aka long unsigned int *}’ [-Wformat=]
  scanf("...