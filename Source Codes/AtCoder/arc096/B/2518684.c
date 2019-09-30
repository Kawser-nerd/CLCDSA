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

#ifdef __cplusplus
#include <queue>
#include <stack>
// #include <tuple>
#include <set>
#include <map>

// using namespace std; // HELL
using std::queue;
using std::priority_queue;
using std::stack;
// using std::tuple;
using std::set;
using std::map;
using std::vector;
using std::greater;
using std::pair;

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



const hw vector8[8] = {
	{-1, -1},
	{-1,  0},
	{-1, +1},
	{ 0, -1},
	{ 0, +1},
	{+1, -1},
	{+1,  0},
	{+1, +1}
};

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

void printUquotient (ull left, ull right) {
	const int32_t digits = 20;

	printf("%llu.", left / right);
	left %= right;
	for (int32_t i = 0; i < digits; i++) {
		left *= 10;
		printf("%1d", left / right);
		left %= right;
	}
	puts("");

	return;
}

void printSquotient (sll left, sll right) {
	if (left * right < 0) putchar('-');
	printUquotient(sdiff(left, 0), sdiff(right, 0));

	return;
}

int bitcount (ull n) {
	int result = 0;
	while (n) {
		if (n & 1) result++;
		n /= 2;
	}
	return result;
}

#ifdef __cplusplus

bool setfind (set<ull> s, ull x) {
	return (s.find(x) != s.end());
}

#endif

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

bool isinrange (sll left, sll x, sll right) {
	return (left <= x && x <= right);
}


sll a[N_MAX];
sll b[N_MAX];

char s[N_MAX + 1];

// sll elema[N_MAX + 1];
// sll elemb[N_MAX + 1];
// sll dp[N_MAX + 1][2];
sll eldif[N_MAX + 2];
sll dp[N_MAX + 2];

sll segx[524288], segxbase;
sll segy[524288], segybase;

ull seg_init (ull n, sll elem, sll seg[], ull *segbase) {
	*segbase = 1;
	while (*segbase < n) *segbase *= 2;

	for (sll i = *segbase * 2 - 1; i; i--) {
		if (i >= *segbase) {
			seg[i] = elem;
			continue;
		}

		seg[i] = smin(seg[i * 2], seg[i * 2 + 1]);
	}

	return *segbase;
}

sll seg_update (sll e, ull i, sll seg[], ull base) {
	i += base;
	seg[i] = e;
	while (i /= 2) {
		seg[i] = smin(seg[i * 2], seg[i * 2 + 1]);
	}

	return e;
}

sll seg_direct (ull i, sll seg[], ull base) {
	return seg[base + i];
}

bool seg_append (sll e, ull i, sll seg[], ull base) {
	if (e < seg_direct(i, seg, base)) {
		seg_update(e, i, seg, base);
		return true;
	} else {
		return false;
	}
}

sll seg_find_ (ull l, ull r, ull rangel, ull ranger, ull i, sll seg[]) {
	if (ranger <= l || r <= rangel) {
		return VERYBIG;
	}
	if (l <= rangel && ranger <= r) {
		return seg[i];
	}

	ull med = (rangel + ranger) / 2;
	sll vl = seg_find_(l, r, rangel, med, i * 2, seg);
	sll vr = seg_find_(l, r, med, ranger, i * 2 + 1, seg);
	return smin(vl, vr);
}

sll seg_find (ull l, ull r, sll seg[], ull base) {
	if (l >= r) return VERYBIG;
	return seg_find_(l, r, 0, base, 1, seg);
}

sll dp[N_MAX + 2];
sll dq[N_MAX + 2];

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

	result = 0;

	bool izryt = false;

	while (true) {

		dp[0] = dq[0] = 0;
		for (i = 0; i < n; i++) {
			sll rv = b[i], lv = b[(n - 1) - i];
			sll rc = a[i] - (i ? a[i - 1] : 0),
			    lc = (i ? a[(n - 1) - (i) + 1] : k) - a[(n - 1) - i];
			if (izryt) {
				rc *= 2;
			} else {
				lc *= 2;
			}

			// printf("%lld- %lld, %lld- %lld\n", rv, rc, lv, lc);

			dp[i + 1] = dp[i] + (rv - rc);
			dq[i + 1] = dq[i] + (lv - lc);
		}

		for (i = 0; i < n; i++) {
			dp[i + 1] = smax(dp[i + 1], dp[i]);
			dq[i + 1] = smax(dq[i + 1], dq[i]);
		}

		for (i = 0; i <= n; i++) {
			result = smax(result, dp[i] + dq[n - i]);
		}

		if (izryt) break;
		izryt = true;
	}

	printf("%lld\n", result);
	// printf("%.12lf\n", dresult);
	// puts(s);

	return 0;

	success:
	// puts("YES");
	// puts("Yes");
	// printf("%llu\n", result);
	// puts("0");
	puts("Takahashi");
	return 0;

	fail:
	// puts("NO");
	// puts("No");
	// puts("0");
	puts("-1");
	// puts("-1 -1 -1");
	// puts("Aoki");
	return 1;
}

int32_t main (void) {
	int32_t i, j;
	int32_t x, y;

	// scanf("%lf%lf", &vda, &vdb, &vdc);
	// scanf("%lld%lld%lld%lld", &vsa, &vsb, &vsc, &vsd);
	// scanf("%llu%llu%llu", &vua, &vub, &vuc, &vud);
	// scanf("%llu%llu", &h, &w);
	// scanf("%*llu%*llu");
	scanf("%llu", &n, &m);
	scanf("%llu", &k, &n);
	// scanf("%llu%llu", &vua, &vub, &vuc, &vud, &vue, &vuf);
	// vua--;
	// vub--;
	// scanf("%lld%lld", &vsa, &vsb, &vsc);
	// scanf("%s", s);
	// scanf("%s", t);
	// scanf("%llu", &k);
	// scanf("%llu", &q);
	for (i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
		scanf("%lld", &b[i]);
		// scanf("%llu", &c[i]);
		// a[i]--;
		// b[i]--;
		// c[i]--;
	}
	// scanf("%llu", &q);

	// for (i = 0; i < h; i++) {
	// 	for (j = 0; j < w; j++) {
	// 		scanf("%llu", &a[i][j]);
	// 	}
	// }
	// for (i = 0; i < h; i++) {
	// 	scanf("%s", &s[i]);
	// }

	// scanf("%llu", &k);
	// scanf("%llu", &q);
	solve();

	return 0;
} ./Main.c: In function ‘printUquotient’:
./Main.c:161:9: warning: format ‘%llu’ expects argument of type ‘long long unsigned int’, but argument 2 has type ‘ull {aka long unsigned int}’ [-Wformat=]
  printf("%llu.", left / right);
         ^
./Main.c:165:10: warning: format ‘%d’ expects argument of type ‘int’, but argument 2 has type ‘ull {aka long unsigned int}’ [-Wformat=]
   printf("%1d", left / right);
          ^
./Main.c: In function ‘solve’:
./Main.c:394:9: warning: format ‘%lld’ expects argument of type ‘long long int’, but argument 2 has type ‘sll {aka long int}’ [-Wformat=]
  printf("%lld\n", result);
         ^
./Main.c: In function ‘main’:
./Main.c:427:8: warning: format ‘%llu’ expects argument of type ‘long long unsigned int *’, but argument 2 has type ‘ull * {aka long unsigned int *}’ [-Wformat=]
  scanf("%llu", &n, &m);
        ^
./Main.c:427:8: warning: too many arguments for format [-Wformat-extra-args]
./Main.c:428:8: warning: format ‘%llu’ expects argument of type ‘long long unsigned int ...