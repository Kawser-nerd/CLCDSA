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

hwllc sorted[N_MAX];

ull frac[N_MAX], frev[N_MAX];

ull parent[N_MAX];
ull rank[N_MAX];
void uf_init (ull n) {
	for (ull i = 0; i < n; i++) {
		parent[i] = i;
		rank[i] = 0;
	}
}
ull uf_find (ull x) {
	if (parent[x] == x) return x;
	return parent[x] = uf_find(parent[x]);
}
bool uf_union (ull a, ull b) {
	a = uf_find(a);
	b = uf_find(b);
	if (a == b) return false;

	if (rank[a] < rank[b]) {
		a ^= (b ^= (a ^= b));
	}
	parent[b] = a;
	if (rank[a] == rank[b]) {
		rank[a]++;
	}
	return true;
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

	frac[0] = frev[0] = 1;
	for (i = 1; i <= n; i++) {
		frac[i] = (frac[i - 1] * i) % MOD;
		frev[i] = divide(frev[i - 1], i, MOD);
	}

	uf_init(n);

	for (i = 0; i < n; i++) {
		sorted[i].a = b[i]; // weight
		sorted[i].b = a[i]; // color
		sorted[i].c = i;    // index
	}
	qsort(sorted, n, sizeof(hwllc), ptriplecomp);
	ull standCol = sorted[0].b, standWht = sorted[0].a;
	i = 1;
	while (i < n && standWht + sorted[i].a <= vb) {
		if (sorted[i].b != standCol) break;
		i++;
	}
	ull exI = i, exCol, exWht;
	if (i >= n) {
		exCol = VERYBIG;
		exWht = VERYBIG;
	} else {
		exCol = sorted[i].b;
		exWht = sorted[i].a;
	}

	// printf("%lld/%lld or %lld/%lld\n", standCol, standWht, exCol, exWht);

	i = 1;
	while (i < n && standWht + sorted[i].a <= vb) {
		if (sorted[i].b == standCol) {
			// printf("%lld==%lld %lld+%lld <= %lld?\n", sorted[i].b, exCol, exWht, sorted[i].a, vb);
			if (exWht + sorted[i].a <= vb) {
				uf_union(sorted[exI].c, sorted[i].c);
			}
		} else {
			// printf("%lld!=%lld %lld+%lld <= %lld?\n", sorted[i].b, exCol, standWht, sorted[i].a, vb);
			uf_union(sorted[0].c, sorted[i].c);
		}

		i++;
	}

	for (i = 0; i < n; i++) {
		sorted[i].a = a[i]; // color
		sorted[i].b = b[i]; // weight
		sorted[i].c = i;    // index
	}
	qsort(sorted, n, sizeof(hwllc), ptriplecomp);
	i = 0;
	while (i < n) {
		j = i;
		while (true) {
			i++;
			if (i >= n || sorted[i].a != sorted[j].a || sorted[j].b + sorted[i].b > va) break;
			uf_union(sorted[j].c, sorted[i].c);
		}
		while (i < n && sorted[i].a == sorted[j].a) i++;
	}

	for (i = 0; i < n; i++) {
		sorted[i].a = uf_find(i); // parent
		sorted[i].b = a[i];       // color
		sorted[i].c = i;
	}
	qsort(sorted, n, sizeof(hwllc), ptriplecomp);

	result = 1;
	i = 0;
	while (i < n) {
		j = i;
		while (i < n && sorted[i].a == sorted[j].a) i++;

		ull item = frac[i - j];

		while (j < i) {
			ki = j;
			while (j < i && sorted[j].b == sorted[ki].b) j++;
			item = (item * frev[j - ki]) % MOD;
		}

		result = (result * item) % MOD;
	}

	printf("%lld\n", result);
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
	scanf("%llu", &n, &m);
	// scanf("%llu", &k, &n, &m);
	scanf("%lld%lld", &va, &vb, &vc, &vd);
	// scanf("%llu", &q);
	// scanf("%s", s);
	// scanf("%s", t);
	for (i = 0; i < n; i++) {
		// scanf("%lld%lld", &xy[i].a, &xy[i].b);
		scanf("%lld", &a[i]);
		scanf("%lld", &b[i]);
		// scanf("%lld", &c[i]);
		// scanf("%lld", &d[i]);
		a[i]--;
		// b[i]--;
		// c[i]--;
	}
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
./Main.c:421:9: warning: format ‘%lld’ expects argument of type ‘long long int’, but argument 2 has type ‘ull {aka long unsigned int}’ [-Wformat=]
  printf("%lld\n", result);
         ^
./Main.c: In function ‘main’:
./Main.c:450:8: warning: format ‘%llu’ expects argument of type ‘long long unsigned int *’, but argument 2 has type ‘ull * {aka long unsigned int *}’ [-Wformat=]
  scanf("%llu", &n, &m);
        ^
./Main.c:450:8: warning: too many arguments for format [-Wformat-extra-args]
./Main.c:452:8: warning: format ‘%lld’ expects argument of type ‘long long int *’, but argument 2 has type ‘sll * {aka long int *}’ [-Wformat=]
  scanf("%lld%lld", &va, &vb, &vc, &vd);
        ^
./Main.c:452:8: warning: format ‘%lld’ expects argument of type ‘long long int *’, but argument 3 has type ‘sll * {aka long int *}’ [-Wformat=]
./Main.c:452:8: warning: too many arguments for format [-Wformat-extra-args]
./Main.c:458:9: warning: format ‘%lld’ expects argument of type ‘long long int *’, b...