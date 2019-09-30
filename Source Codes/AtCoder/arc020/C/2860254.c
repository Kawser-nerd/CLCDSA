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

ull parent[N_MAX];
ull rank[N_MAX];
void uf_init (ull n) {
	for (sll i = 0; i < n; i++) {
		parent[i] = i;
		rank[i] = 0;
	}
}
ull uf_find (ull x) {
	if (parent[x] == x) return x;
	return parent[x] = uf_find(parent[x]);
}
sll uf_union (ull a, ull b) {
	a = uf_find(a);
	b = uf_find(b);
	if (a == b) return -1;

	if (rank[a] > rank[b]) {
		a ^= (b ^= (a ^= b));
	}

	parent[a] = b;
	if (rank[a] == rank[b]) {
		rank[b]++;
	}

	return b;
}


ull a[N_MAX];
// sll a[3001][3001];
sll b[N_MAX];
// sll b[3001][3001];
sll c[N_MAX];
char s[N_MAX + 1];
// char s[3010][3010];
// char t[N_MAX + 1];
// char t[3010][3010];
// hwll xy[N_MAX];

typedef ull mat2[2][2];
typedef ull vec2[2];

ull dig (ull x) {
	if (!x) return 0;
	return dig(x / 10) + 1;
}

void vecmul (vec2 l, mat2 r) {
	vec2 ret;
	for (int i = 0; i < 2; i++) {
		ret[i] = 0;
		for (int ki = 0; ki < 2; ki++) {
			ret[i] += l[ki] * r[ki][i];
			ret[i] %= m;
		}
	}

	// return ret;
	for (int i = 0; i < 2; i++) l[i] = ret[i];
}
void matmul (mat2 l, mat2 r) {
	mat2 ret;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			ret[i][j] = 0;
			for (int ki = 0; ki < 2; ki++) {
				ret[i][j] += l[i][ki] * r[ki][j];
				ret[i][j] %= m;
			}
		}
	}

	// return ret;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			l[i][j] = ret[i][j];
		}
	}
}

ull powmat (ull x, ull d) {
	vec2 v = {1, 1};

	mat2 power = {{bitpow(10, d, m), 0}, {1, 1}};

	while (x) {
		if (x & 1) {
			// v = vecmul(v, power);
			vecmul(v, power);
		}

		// power = matmul(power, power);
		matmul(power, power);
		x /= 2;
	}

	return v[0];
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

	result = 0;
	for (i = 0; i < n; i++) {
		ull d = dig(a[i]);

		result = result * bitpow(10, d * b[i], m) % m;
		result = (result + powmat(b[i] - 1, d) * a[i]) % m;
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
	puts("Takahashi");
	return 0;

	fail:
	// puts("NO");
	// puts("No");
	// puts("0");
	// puts("-1");
	// puts("-1 -1 -1");
	puts("Aoki");
	return 1;
}

int32_t main (void) {
	int32_t i, j;
	int32_t x, y;

	// scanf("%lf%lf", &vda, &vdb, &vdc);
	// scanf("%lld%lld", &vsa, &vsb, &vsc, &vsd);
	// scanf("%llu%llu", &vua, &vub, &vuc, &vud);
	// scanf("%*llu%*llu");
	// scanf("%llu%llu", &h, &w);
	scanf("%llu", &n, &m);
	// scanf("%llu", &k, &n, &m);
	// scanf("%s", s);
	// scanf("%s", t);
	// scanf("%llu", &q);
	for (i = 0; i < n; i++) {
		// scanf("%lld%lld", &xy[i].a, &xy[i].b);
		scanf("%lld", &a[i]);
		scanf("%lld", &b[i]);
		// scanf("%lld", &c[i]);
		// scanf("%lld", &t[i]);
		// a[i]--;
		// b[i]--;
		// c[i]--;
	}
	scanf("%llu", &m, &k);
	// for (i = 0; i < w; i++) {
	// 	scanf("%llu", &b[i]);
	// 	// b[i]--;
	// }
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
./Main.c:388:9: warning: format ‘%llu’ expects argument of type ‘long long unsigned int’, but argument 2 has type ‘ull {aka long unsigned int}’ [-Wformat=]
  printf("%llu\n", result);
         ^
./Main.c: In function ‘main’:
./Main.c:421:8: warning: format ‘%llu’ expects argument of type ‘long long unsigned int *’, but argument 2 has type ‘ull * {aka long unsigned int *}’ [-Wformat=]
  scanf("%llu", &n, &m);
        ^
./Main.c:421:8: warning: too many arguments for format [-Wformat-extra-args]
./Main.c:428:9: warning: format ‘%lld’ expects argument of type ‘long long int *’, but argument 2 has type ‘ull * {aka long unsigned int *}’ [-Wformat=]
   scanf("%lld", &a[i]);
         ^
./Main.c:429:9: warning: format ‘%lld’ expects argument of type ‘long long int *’, but argument 2 has type ‘sll * {aka long int *}’ [-Wformat=]
   scanf("%lld", &b[i]);
         ^
./Main.c:436:8: warning: format ‘%llu’ expects argument of type ‘long long unsigned int *’, but argument 2 has type ‘ull ...