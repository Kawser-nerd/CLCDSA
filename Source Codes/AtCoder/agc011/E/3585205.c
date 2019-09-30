#if 0
cat <<EOF >mistaken-paste
#endif
// thanks for @rsk0315_h4x

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
#define VERYBIG 2000000000000007LL

#define MOD 1000000007
#define FOD  998244353
typedef uint64_t ull;
typedef  int64_t sll;

#define N_MAX 1000000


ull n, m;

sll a[N_MAX + 5];
char s[N_MAX + 1];

bool func (ull x) {
	ull dsum = 0;
	ull flow = 0;
	ull xv = x;
	for (sll i = 0; i < n; i++) {
		flow += a[i] + xv % 10;
		dsum += flow % 10;
		flow /= 10;
		xv /= 10;
	}

	return (dsum <= x);
}

ull solve () {
	sll i, j, ki, li;
	sll result = 0;
	sll sum = 0;

	n = strlen(s);
	j = n - 1;
	sum = 0;
	for (i = 0; i < n + 10; i++) {

		if (j >= 0) {
			sum += (s[j] - '0') * 9;
		}
		a[i] = sum % 10;
		sum /= 10;

		j--;
	}

	n += 10;

	ull ok = VERYBIG, ng = 0;
	while (ng + 1 < ok) {
		ull med = (ok + ng) / 2;
		if (func(med)) {
			ok = med;
		} else {
			ng = med;
		}
	}
	result = (ok - 1) / 9 + 1;

	printf("%lld\n", result);
	return 0;
}

int32_t main (void) {
	scanf("%s", s);
	solve();
	return 0;
} ./Main.c: In function ‘solve’:
./Main.c:79:9: warning: format ‘%lld’ expects argument of type ‘long long int’, but argument 2 has type ‘sll {aka long int}’ [-Wformat=]
  printf("%lld\n", result);
         ^
./Main.c: In function ‘main’:
./Main.c:84:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s", s);
  ^