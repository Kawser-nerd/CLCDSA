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
sll va, vb, vc, vd, ve, vf;
ull ua, ub, uc, ud, ue, uf;
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

int32_t pdoublecomp (const void *left, const void *right) {
	double l = *(double*)left;
	double r = *(double*)right;
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

sll a[N_MAX];
// sll a[3001][3001];
sll b[N_MAX];
// sll b[3001][3001];
// sll c[N_MAX];
// sll d[N_MAX];
char s[N_MAX + 1];
// char s[3010][3010];
char t[N_MAX + 1];
// char t[3010][3010];
// hwll xy[N_MAX];

hwll dp[20000];
sll sb[2][3], sc[3][2];

ull hibit (ull x, ull d) {
	if (!d) return (x % 3);
	return hibit(x / 3, d - 1);
}
ull bits (ull x) {
	ull r = 0;
	for (ull i = 0; i < 9; i++) {
		if ((x % 3) == 0) r++;
		x /= 3;
	}
	return r;
}

hwll sorted[N_MAX];

hwll ryona (ull x[9]) {
	hwll ret = {0, 0};
	sll i, j;

	ull xx[3][3];
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			xx[i][j] = x[i * 3 + j];
		}
	}

	for (i = 0; i < 2; i++) {
		for (j = 0; j < 3; j++) {
			if (xx[i][j] == xx[i + 1][j]) {
				ret.a += sb[i][j];
			} else {
				ret.b += sb[i][j];
			}
		}
	}
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 2; j++) {
			if (xx[i][j] == xx[i][j + 1]) {
				ret.a += sc[i][j];
			} else {
				ret.b += sc[i][j];
			}
		}
	}

	return ret;
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

	ull pows[9] = {1};
	for (i = 1; i < 9; i++) {
		pows[i] = pows[i - 1] * 3;
	}

	for (i = 0; i < 2; i++) {
		for (j = 0; j < 3; j++) {
			scanf("%llu", &sb[i][j]);
		}
	}
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 2; j++) {
			scanf("%llu", &sc[i][j]);
		}
	}

	for (i = 0; i < 19683; i++) {
		sorted[i].a = i;
		sorted[i].b = bits(i);
	}
	qsort(sorted, 19683, sizeof(hwll), phwllREVcomp);

	for (i = 0; i < 19683; i++) {
		ull v = sorted[i].a;
		// printf("%lld: %lld\n", v, sorted[i].b);

		ull bs[9];
		ull ns[9] = {0};
		ki = v;
		for (j = 0; j < 9; j++) {
			bs[j] = (ki % 3);
			ki /= 3;

			ns[bs[j]]++;
		}

		if (ns[0] == 0) {
			dp[v] = ryona(bs);
		} else if (ns[1] == ns[2]) {
			// Choku

			dp[v].a = -100;
			for (j = 0; j < 9; j++) {
				if (bs[j] == 0) {
					maybe = v + pows[j] * 1;
					if (dp[maybe].a > dp[v].a) {
						dp[v] = dp[maybe];
					}
				}
			}
		} else if (ns[1] == ns[2] + 1) {
			// Naoko

			dp[v].b = -100;
			for (j = 0; j < 9; j++) {
				if (bs[j] == 0) {
					maybe = v + pows[j] * 2;
					if (dp[maybe].b > dp[v].b) {
						dp[v] = dp[maybe];
					}
				}
			}
		} else {
			dp[v].a = dp[v].b = -VERYBIG;
		}

		// if (dp[v].a > -VERYBIG) printf("[%lld]: %lld/%lld\n", v, dp[v].a, dp[v].b);
		// fflush(stdout);
	}

	printf("%lld\n%lld\n", dp[0].a, dp[0].b);

	// printf("%lld\n", result);
	// printf("%.15lf\n", dresult);
	// puts(s);

	return 0;

	success:
	// puts("YES");
	puts("Yes");
	// printf("%llu\n", result);
	// puts("0");
	// puts("Alice");
	return 0;

	fail:
	// puts("NO");
	puts("No");
	// puts("0");
	// puts("-1");
	// puts("-1 -1 -1");
	// puts("Bob");
	return 1;
}

int32_t main (void) {
	int32_t i, j;
	int32_t x, y;

	// scanf("%llu%llu", &h, &w);
	// scanf("%llu", &n, &m);
	// scanf("%llu", &k, &n, &m);
	// scanf("%lld%lld", &va, &vb, &vc, &vd);
	// scanf("%llu", &q);
	// scanf("%s", s);
	// scanf("%s", t);
	// for (i = 0; i < n; i++) {
	// 	// scanf("%lld%lld", &xy[i].a, &xy[i].b);
	// 	scanf("%lld", &a[i]);
	// 	// scanf("%lld", &b[i]);
	// 	// scanf("%lld", &c[i]);
	// 	// scanf("%lld", &d[i]);
	// 	// a[i]--;
	// 	// b[i]--;
	// 	// c[i]--;
	// }
	// scanf("%llu", &m, &k);
	// scanf("%llu", &q);
	// for (i = 0; i < m; i++) {
	// 	scanf("%lld", &b[i]);
	// }

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
./Main.c:361:10: warning: format ‘%llu’ expects argument of type ‘long long unsigned int *’, but argument 2 has type ‘sll * {aka long int *}’ [-Wformat=]
    scanf("%llu", &sb[i][j]);
          ^
./Main.c:366:10: warning: format ‘%llu’ expects argument of type ‘long long unsigned int *’, but argument 2 has type ‘sll * {aka long int *}’ [-Wformat=]
    scanf("%llu", &sc[i][j]);
          ^
./Main.c:424:9: warning: format ‘%lld’ expects argument of type ‘long long int’, but argument 2 has type ‘sll {aka long int}’ [-Wformat=]
  printf("%lld\n%lld\n", dp[0].a, dp[0].b);
         ^
./Main.c:424:9: warning: format ‘%lld’ expects argument of type ‘long long int’, but argument 3 has type ‘sll {aka long int}’ [-Wformat=]
./Main.c:361:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%llu", &sb[i][j]);
    ^
./Main.c:366:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunuse...