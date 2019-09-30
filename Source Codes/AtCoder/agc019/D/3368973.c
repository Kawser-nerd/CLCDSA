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

typedef struct {
	sll a;
	sll b;
	sll c;
} hwllc;

ull n;

ull umin (ull x, ull y) {
	return (x < y) ? x : y;
}

ull umax (ull x, ull y) {
	return (x > y) ? x : y;
}

sll smin (sll x, sll y) {
	return (x < y) ? x : y;
}

sll smax (sll x, sll y) {
	return (x > y) ? x : y;
}

sll sdiff (sll a, sll b) {
	if (a >= b) {
		return a - b;
	} else {
		return b - a;
	}
}

int32_t ptriplecomp (const void *left, const void *right) {
	hwllc l = *(hwllc*)left;
	hwllc r = *(hwllc*)right;

	if (l.a < r.a) {
		return -1;
	}
	if (l.a > r.a) {
		return +1;
	}
	if (l.b < r.b) {
		return -1;
	}
	if (l.b > r.b) {
		return +1;
	}
	if (l.c < r.c) {
		return -1;
	}
	if (l.c > r.c) {
		return +1;
	}
	return 0;
}

char s[N_MAX + 1];
char t[N_MAX + 1];

hwllc roll[N_MAX];
bool must[N_MAX];

sll f (sll l, sll r, sll f) {
	return l + r + smin(r + sdiff(l, f) % n, l + sdiff(n - r, f) % n);
}

ull solve () {
	sll i, j, ki, li;
	// ull result = 0;
	sll result = 0;
	sll sum = 0;

	n = strlen(s);

	sll v = -1;
	for (i = 0; i < n; i++) {
		if (t[i] == '1') {
			v = i;
			break;
		}
	}
	if (v < 0) {
		for (i = 0; i < n; i++) {
			if (s[i] == '1') break;
		}
		if (i == n) {
			puts("0");
		} else {
			puts("-1");
		}
		return 0;
	}

	for (i = 0; i < n; i++) {
		ull curr = (v + i) % n;
		if (t[curr] == '1') {
			sum = 0;
		} else {
			sum++;
		}
		roll[curr].a = sum;
		roll[curr].c = curr;
	}
	for (i = 0; i < n; i++) {
		ull curr = (n + v - i) % n;
		if (t[curr] == '1') {
			sum = 0;
		} else {
			sum++;
		}
		roll[curr].b = sum;
	}
	qsort(roll, n, sizeof(hwllc), ptriplecomp);

	result = VERYBIG;
	for (i = 0; i < n; i++) {
		ull flips = 0;
		for (j = 0; j < n; j++) {
			if (must[j] = (t[(n + j - i) % n] != s[j])) flips++;
		}

		ull shifts = VERYBIG;
		sll l = n, r = 0;

		j = n - 1;
		while (l >= 0) {
			shifts = umin(shifts, f(l, r, i));

			while (j >= 0) {
				if (!must[roll[j].c]) {
					j--;
					continue;
				}
				if (roll[j].a < l) break;
				r = smax(r, roll[j].b);
				j--;
			}

			l--;
		}

		result = umin(result, flips + shifts);
	}

	printf("%lld\n", result);
	return 0;
}

int32_t main (void) {
	scanf("%s", s);
	scanf("%s", t);

	solve();

	return 0;
} ./Main.c: In function ‘solve’:
./Main.c:172:9: warning: format ‘%lld’ expects argument of type ‘long long int’, but argument 2 has type ‘sll {aka long int}’ [-Wformat=]
  printf("%lld\n", result);
         ^
./Main.c: In function ‘main’:
./Main.c:177:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s", s);
  ^
./Main.c:178:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s", t);
  ^