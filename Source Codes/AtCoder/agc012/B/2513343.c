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


ull mergeteq (ull a[], ull n) {
	ull l = n / 2, r = n - l;
	if (n == 1) return 0;
	ull ret = mergeteq(a, l) + mergeteq(a + l, r);

	ull tmp[n];
	sll i = 0, j = 0;
	while (i < l || j < r) {
		if (i == l) {
			tmp[i + j] = a[i + j];
			j++;
			continue;
		}
		if (j == r) {
			tmp[i + j] = a[i];
			i++;
			continue;
		}

		if (a[i] > a[l + j]) {
			tmp[i + j] = a[l + j];
			ret += l - i;
			j++;
		} else {
			tmp[i + j] = a[i];
			i++;
		}
	}

	for (i = 0; i < n; i++) {
		a[i] = tmp[i];
	}
	return ret;
}

ull parent[N_MAX];
ull rank[N_MAX];

ull uf_init (ull n) {
	sll i;
	for (i = 0; i < n; i++) {
		parent[i] = i;
		rank[i] = 0;
	}

	return n;
}
ull uf_find (ull x) {
	if (parent[x] == x) return x;
	return parent[x] = uf_find(parent[x]);
}
ull uf_unite (ull a, ull b) {
	a = uf_find(a);
	b = uf_find(b);
	if (a == b) return 0;

	if (rank[a] > rank[b]) {
		parent[b] = a;
	} else {
		parent[a] = b;
		if (rank[a] == rank[b]) {
			rank[b]++;
		}
	}

	return 1;
}

sll a[N_MAX];
sll b[N_MAX];

sll v[N_MAX], d[N_MAX], c[N_MAX];

char s[N_MAX + 1];

hwll sorted[N_MAX * 2];
ull stlen[N_MAX];

ull dp[N_MAX];
ull wide[N_MAX];

ull color (sll v, sll d, sll c) {
	sll i, j;

	if (dp[v] && wide[v] >= d) return 0;
	// printf("%llu/%llu/%llu\n", v, d, c);
	if (!dp[v]) dp[v] = c;
	wide[v] = d;
	if (!d) return 0;

	for (i = stlen[v]; i < m * 2 && sorted[i].a == v; i++) {
		ull u = sorted[i].b;
		// printf("%llu? (%llu, %llu)\n", u, dp[u], wide[u]);

		if (dp[u] && wide[u] >= d) continue;
		color(u, d - 1, c);
	}

	return 0;
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

	for (i = 0; i < m; i++) {
		sorted[i * 2].a = sorted[i * 2 + 1].b = a[i];
		sorted[i * 2 + 1].a = sorted[i * 2].b = b[i];
	}
	qsort(sorted, m * 2, sizeof(hwll), phwllABcomp);
	i = 0;
	ki = 0;
	while (ki < n) {
		stlen[ki] = i;

		j = i;
		while (j < m * 2 && sorted[j].a == ki) {
			// printf("%llu/%llu.\n", sorted[j].a, sorted[j].b);
			j++;
		}
		// puts("===");
		i = j;
		ki++;
	}

	for (i = q - 1; i >= 0; i--) {
		// printf("%lld start!\n", i);
		color(v[i], d[i], c[i]);
	}

	for (i = 0; i < n; i++) {
		printf("%llu\n", dp[i]);
	}

	// printf("%lld\n", result);
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
	scanf("%llu%llu", &n, &m);
	// scanf("%llu", &k, &n);
	// scanf("%llu%llu", &vua, &vub, &vuc, &vud, &vue, &vuf);
	// scanf("%lld%lld", &vsa, &vsb, &vsc);
	// scanf("%s", s);
	// scanf("%s", t);
	// scanf("%llu", &k);
	// scanf("%llu", &q);
	for (i = 0; i < m; i++) {
		scanf("%lld", &a[i]);
		scanf("%lld", &b[i]);
		// scanf("%llu", &c[i]);
		a[i]--;
		b[i]--;
		// c[i]--;
	}
	scanf("%llu", &q);
	for (i = 0; i < q; i++) {
		scanf("%llu%llu%llu", &v[i], &d[i], &c[i]);
		v[i]--;
	}
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
./Main.c:410:10: warning: format ‘%llu’ expects argument of type ‘long long unsigned int’, but argument 2 has type ‘ull {aka long unsigned int}’ [-Wformat=]
   printf("%llu\n", dp[i]);
          ^
./Main.c: In function ‘main’:
./Main.c:446:8: warning: format ‘%llu’ expects argument of type ‘long long unsigned int *’, but argument 2 has type ‘ull * {aka long unsigned int *}’ [-Wformat=]
  scanf("%llu%llu", &n, &m);
        ^
./Main.c:446:8: warning: format ‘%llu’ expects argument of type ‘long long unsigned int *’, but argument 3 has type ‘ull * {aka long unsigned...