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
#define VERYBIG 2000000000000007LL

#define MOD 1000000007
#define FOD  998244353
typedef uint64_t ull;
typedef  int64_t sll;

#define N_MAX 1000000
#define M_MAX 200000

#ifdef __cplusplus
#include <queue>
#include <stack>
#include <tuple>
#include <set>
#include <map>
#include <string>

using std::queue;
using std::priority_queue;
using std::stack;
using std::tuple;
using std::set;
using std::map;
using std::vector;
using std::greater;
using std::pair;
using std::string;

#endif

typedef struct {
	int32_t a;
	int32_t b;
} hw;

typedef struct {
	sll a;
	sll b;
} hwll;

typedef struct {
	sll a;
	sll b;
	sll c;
} hwllc;

typedef struct {
	hwll a;
	hwll b;
} linell;

ull n, m;
ull h, w;
ull k;
ull q;
ull vua, vub, vuc, vud, vue, vuf;
sll vsa, vsb, vsc, vsd, vse, vsf;
long double vra, vrb, vrc;
double vda, vdb, vdc;
char ch, dh;

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

ull gcd (ull x, ull y) {
	if (x < y) {
		return gcd(y, x);
	} else if (y == 0) {
		return x;
	} else {
		return gcd(y, x % y);
	}
}

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

ull udiff (ull a, ull b) {
	if (a >= b) {
		return a - b;
	} else {
		return b - a;
	}
}

sll sdiff (sll a, sll b) {
	if (a >= b) {
		return a - b;
	} else {
		return b - a;
	}
}

int bitcount (ull n) {
	int result = 0;
	while (n) {
		if (n & 1) result++;
		n /= 2;
	}
	return result;
}

// double distance (sll x1, sll y1, sll x2, sll y2) {
// 	double xdist2, ydist2, origindist, dist;

// 	xdist2 = (x1 - x2) * (x1 - x2);
// 	ydist2 = (y1 - y2) * (y1 - y2);
// 	return sqrt(xdist2 + ydist2);
// }

int32_t pullcomp (const void *left, const void *right) {
	ull l = *(ull*)left;
	ull r = *(ull*)right;
	if (l < r) {
		return -1;
	}
	if (l > r) {
		return +1;
	}
	return 0;
}

int32_t psllcomp (const void *left, const void *right) {
	sll l = *(sll*)left;
	sll r = *(sll*)right;
	if (l < r) {
		return -1;
	}
	if (l > r) {
		return +1;
	}
	return 0;
}

int32_t pcharcomp (const void *left, const void *right) {
	char l = *(char*)left;
	char r = *(char*)right;
	if (l < r) {
		return -1;
	}
	if (l > r) {
		return +1;
	}
	return 0;
}

int32_t pstrcomp (const void *left, const void *right) {
	char* l = *(char**)left;
	char* r = *(char**)right;

	return strcmp(l, r);
}

int32_t phwllABcomp (const void *left, const void *right) {
	hwll l = *(hwll*)left;
	hwll r = *(hwll*)right;
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
	return 0;
}

int32_t phwllREVcomp (const void *left, const void *right) {
	hwll l = *(hwll*)left;
	hwll r = *(hwll*)right;
	if (l.b < r.b) {
		return -1;
	}
	if (l.b > r.b) {
		return +1;
	}
	if (l.a < r.a) {
		return -1;
	}
	if (l.a > r.a) {
		return +1;
	}
	return 0;
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

bool isinrange (sll left, sll x, sll right) {
	return (left <= x && x <= right);
}

bool isinrange_soft (sll left, sll x, sll right) {
	return (left <= x && x <= right) || (left >= x && x >= right);
}

#define SZ sizeof

ull a[N_MAX];
// sll a[3001][3001];
sll b[N_MAX];
// sll b[3001][3001];
sll c[N_MAX];
char s[N_MAX + 1];
// char s[3010][3010];
char t[N_MAX + 1];
// char t[3010][3010];
// hwll xy[N_MAX];

char *sorted[N_MAX];

ull acxor (ull x) {
	ull ret = 0;

	for (sll bits = 63; bits >= 0; bits--) {
		bool isbit;
		if (bits == 63) {
			isbit = ((x >> 63) ? true : false);
		} else {
			ull hoge = x - (1ull << bits);
			if (hoge & (1ull << (bits + 1))) {
				isbit = false;
			} else {
				isbit = true;
			}
		}


		if (isbit) {
			ret ^= (1 << bits);
		}
	}

	return ret;
}

ull samelen (sll i, sll j) {
	sll li;
	for (li = 0; sorted[i][li] && sorted[j][li]; li++) {
		if (sorted[i][li] != sorted[j][li]) break;
	}
	return li;
}

ull mofu (ull x) {
	return (x & (-x));
}

ull solve () {
	sll i, j, ki, li;
	ull result = 0;
	// sll result = 0;
	double dresult = 0;
	// ull maybe = 0;
	sll maybe = 0;
	// ull sum = 0;
	sll sum = 0;
	sll item;
	ull *dpcell;

	sorted[0] = s;
	for (i = 0; i < n; i++) {
		scanf("%s", sorted[i]);
		sorted[i + 1] = sorted[i] + strlen(sorted[i]) + 1;
	}
	qsort(sorted, n, sizeof(char*), pstrcomp);

	result = 0;
	for (i = 0; i < n; i++) {
		ull del;
		if (!i) {
			del = acxor(k);
			// printf("acxor(%llu)", k);
		} else {
			// del = mofu(k - samelen(i - 1, i));
			del = acxor(k - samelen(i - 1, i));
			// printf("acxor(%llu - %llu)", k, samelen(i - 1, i));
		}
		// printf("=%llu ", del);

		del ^= acxor(k - (sll)strlen(sorted[i]));
		// printf(" ->XOR acxor(%llu - %llu) ->=%llu ", k, (sll)strlen(sorted[i]), del);
		result ^= del;

		// printf("%s -> %llu...\n", sorted[i], result);
	}

	if (result) {
		goto success;
	} else {
		goto fail;
	}

	printf("%llu\n", result);
	// printf("%.15lf\n", dresult);
	// puts(s);

	return 0;

	success:
	// puts("YES");
	// puts("Yes");
	// printf("%llu\n", result);
	// puts("0");
	puts("Alice");
	return 0;

	fail:
	// puts("NO");
	// puts("No");
	// puts("0");
	// puts("-1");
	// puts("-1 -1 -1");
	puts("Bob");
	return 1;
}

int32_t main (void) {
	int32_t i, j;
	int32_t x, y;

	// scanf("%lf%lf", &vda, &vdb, &vdc);
	// scanf("%lld%lld", &vsa, &vsb, &vsc, &vsd);
	// scanf("%llu%llu%llu", &vua, &vub, &vuc, &vud);
	// scanf("%*llu%*llu");
	// scanf("%llu%llu", &h, &w);
	scanf("%llu", &n, &m);
	scanf("%llu", &k, &n, &m);
	// scanf("%s", s);
	// scanf("%s", t);
	// scanf("%llu", &q);
	// for (i = 0; i < n; i++) {
	// 	// scanf("%lld%lld", &xy[i].a, &xy[i].b);
	// 	scanf("%lld", &a[i]);
	// 	// scanf("%lld", &b[i]);
	// 	// scanf("%lld", &c[i]);
	// 	// scanf("%lld", &t[i]);
	// 	// a[i]--;
	// 	// b[i]--;
	// 	// c[i]--;
	// }
	// scanf("%llu", &m, &k);
	// scanf("%llu", &q);

	// for (i = 0; i < h; i++) {
	// 	for (j = 0; j < w; j++) {
	// 		scanf("%llu", &a[i][j]);
	// 	}
	// }
	// for (i = 0; i < h; i++) {
	// 	scanf("%s", &s[i]);
	// }

	solve();

	return 0;
} ./Main.c: In function ‘solve’:
./Main.c:364:9: warning: format ‘%llu’ expects argument of type ‘long long unsigned int’, but argument 2 has type ‘ull {aka long unsigned int}’ [-Wformat=]
  printf("%llu\n", result);
         ^
./Main.c: In function ‘main’:
./Main.c:397:8: warning: format ‘%llu’ expects argument of type ‘long long unsigned int *’, but argument 2 has type ‘ull * {aka long unsigned int *}’ [-Wformat=]
  scanf("%llu", &n, &m);
        ^
./Main.c:397:8: warning: too many arguments for format [-Wformat-extra-args]
./Main.c:398:8: warning: format ‘%llu’ expects argument of type ‘long long unsigned int *’, but argument 2 has type ‘ull * {aka long unsigned int *}’ [-Wformat=]
  scanf("%llu", &k, &n, &m);
        ^
./Main.c:398:8: warning: too many arguments for format [-Wformat-extra-args]
./Main.c: In function ‘solve’:
./Main.c:333:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", sorted[i]);
   ^
./Main.c: In function ‘main’:...