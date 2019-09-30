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

#ifdef __cplusplus
#include <queue>
#include <stack>
#include <tuple>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <functional>
#include <array>

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
using std::get;

template <typename T, typename U>
pair<T, U> operator+(pair<T, U> l, pair<T, U> r) {
	return pair<T, U>(l.first + r.first, l.second + r.second);
}

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

#define BEGCMP(NAME) int32_t NAME (const void *left, const void *right)
#define DEFLR(TYPE) TYPE l=*(TYPE*)left,r=*(TYPE*)right
#define CMPRET(L, R) if((L)<(R))return-1;if((L)>(R))return+1

// int32_t pullcomp (const void *left, const void *right) {
// 	ull l = *(ull*)left;
// 	ull r = *(ull*)right;
// 	if (l < r) {
// 		return -1;
// 	}
// 	if (l > r) {
// 		return +1;
// 	}
// 	return 0;
// }
BEGCMP(pullcomp){
	DEFLR(ull);
	CMPRET(l, r);
	return 0;
}
BEGCMP(prevcomp){
	DEFLR(ull);
	CMPRET(r, l);
	return 0;
}
BEGCMP(psllcomp){
	DEFLR(sll);
	CMPRET(l, r);
	return 0;
}
BEGCMP(pcharcomp){
	DEFLR(char);
	CMPRET(l, r);
	return 0;
}
BEGCMP(pdoublecomp){
	DEFLR(double);
	CMPRET(l, r);
	return 0;
}

int32_t pstrcomp (const void *left, const void *right) {
	char* l = *(char**)left;
	char* r = *(char**)right;

	return strcmp(l, r);
}

BEGCMP(phwllABcomp){
	DEFLR(hwll);
	CMPRET(l.a, r.a);
	CMPRET(l.b, r.b);
	return 0;
}
BEGCMP(phwllREVcomp){
	DEFLR(hwll);
	CMPRET(l.b, r.b);
	CMPRET(l.a, r.a);
	return 0;
}
BEGCMP(ptriplecomp){
	DEFLR(hwllc);
	CMPRET(l.a, r.a);
	CMPRET(l.b, r.b);
	CMPRET(l.c, r.c);
	return 0;
}
BEGCMP(ptripleREVcomp){
	DEFLR(hwllc);
	CMPRET(l.b, r.b);
	CMPRET(l.a, r.a);
	CMPRET(l.c, r.c);
	return 0;
}

int32_t pquadcomp (const void *left, const void *right) {
	linell l = *(linell*)left;
	linell r = *(linell*)right;

	sll ac = phwllABcomp(&(l.a), &(r.a));
	if (ac) return ac;
	sll bc = phwllABcomp(&(l.b), &(r.b));
	if (bc) return bc;

	return 0;
}

bool isinrange (sll left, sll x, sll right) {
	return (left <= x && x <= right);
}

bool isinrange_soft (sll left, sll x, sll right) {
	return (left <= x && x <= right) || (left >= x && x >= right);
}

sll a[N_MAX + 5];
// ull a[N_MAX + 5];
// sll a[3001][3001];
sll b[N_MAX + 5];
// ull b[N_MAX + 5];
// sll b[3001][3001];
sll c[N_MAX + 5];
sll d[N_MAX + 5];
sll e[N_MAX];
char s[N_MAX + 1];
// char s[3010][3010];
char t[N_MAX + 1];
// char t[3010][3010];
char u[N_MAX + 1];
hwll xy[N_MAX + 5];
hwllc tup[N_MAX + 5];
// sll table[3005][3005];
ull gin[N_MAX];
// here we go

hwll bits[N_MAX];

ull vs[N_MAX], vlen = 0;
ull termiL[N_MAX][20], termiR[N_MAX][20];
sll dpL[1 << 20], dpR[1 << 20];

sll req[N_MAX];

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

	while (true) {
		vs[vlen] = k;
		vlen++;
		if (!k) break;
		k /= 2;
	}

	sll tnal;

	for (i = 0; i < vlen; i++) {
		tnal = n - 1;
		for (j = n - 1; j >= 0; j--) {
			termiR[j][i] = tnal;
			// printf("%lld-> %lld (%lld)\n", j, tnal, i);

			if (j && a[j] - a[j - 1] > vs[i]) tnal = j - 1;
		}
		tnal = 0;
		for (j = 0; j < n; j++) {
			termiL[j][i] = tnal;
			// printf("<-%lld %lld (%lld)\n", j, tnal, i);

			if (j < n - 1 && a[j + 1] - a[j] > vs[i]) tnal = j + 1;
		}
	}

	ull bitlen = (1LL << vlen) / 2;
	for (i = 0; !(i >> (vlen)); i += 2) {
		bits[i / 2] = (hwll){bitcount(i), i};
	}
	qsort(bits, bitlen, sizeof(hwll), phwllABcomp);

	dpL[0] = -1;
	for (i = 1; i < bitlen; i++) {
		ull v = bits[i].b;

		dpL[v] = -1;
		for (j = 1; j < vlen; j++) {
			if (!(v & (1LL << j))) continue;

			ull prev = v ^ (1LL << j);
			sll pdp = dpL[prev];
			if (pdp == n - 1) {
				dpL[v] = n - 1;
			} else {
				dpL[v] = smax(dpL[v], termiR[pdp + 1][j]);
			}
		}
		// printf("L %lld; %llu\n", v, dpL[v]);
	}
	dpR[0] = n;
	for (i = 1; i < bitlen; i++) {
		ull v = bits[i].b;

		dpR[v] = n;
		for (j = 1; j < vlen; j++) {
			if (!(v & (1LL << j))) continue;

			ull prev = v ^ (1LL << j);
			sll pdp = dpR[prev];
			if (pdp == 0) {
				dpR[v] = 0;
			} else {
				dpR[v] = smin(dpR[v], termiL[pdp - 1][j]);
			}
		}
		// printf("R %lld; %llu\n", v, dpR[v]);
	}

	for (i = 0; i < n; i++) {
		req[i] = -1;
	}
	bool isall = false;
	for (i = 0; i < bitlen; i++) {
		ull v = bits[i].b;
		ull u = bits[bitlen - 1].b ^ v;

		if (dpL[v] + 1 >= dpR[u]) {
			isall = true;
			break;
		}
		req[dpR[u] - 1] = smax(req[dpR[u] - 1], dpL[v] + 1);
	}
	for (i = 1; i < n; i++) {
		req[i] = smax(req[i], req[i - 1]);
	}

	for (i = 0; i < n; i++) {
		sll coverL = termiL[i][0], coverR = termiR[i][0];

		// printf("%lld: %lld ~ %lld\n", i, coverL, coverR);
		if (isall || req[coverR] >= coverL) {
			puts("Possible");
		} else {
			puts("Impossible");
		}
	}

	// printf("%lld\n", result);
	// printf("%.15lf\n", dresult);
	// puts(s);

	return 0;

	success:
	// puts("YES");
	puts("Yes");
	// printf("%llu\n", result);
	// puts("0");
	// puts("Hanako");
	return 0;

	fail:
	// puts("NO");
	// puts("No");
	puts("0");
	// puts("-1");
	// puts("-1 -1 -1");
	// puts("Jiro");
	return 1;
}

int32_t main (int argc, char *argv[]) {
	int32_t i, j;

	n = 3;
	m = 0;

	// scanf("%llu%llu", &h, &w);
	scanf("%llu", &n, &m);
	scanf("%llu", &k, &n, &m);
	// scanf("%llu%llu", &h, &w);
	// scanf("%s", s);
	// scanf("%llu", &q);
	// scanf("%lld%lld", &va, &vb, &vc, &vd);
	// scanf("%llu%llu%llu", &ua, &ub, &uc, &ud, &ue);
	// scanf("%s", t);
	// scanf("%s", u);
	// scanf("%llu", &k);
	// scanf("%lld", &m);
	// for (i = 0; i < n; i++) {
	// 	scanf("%llu", &d[i]);
	// }
	for (i = 0; i < n; i++) {
		// scanf("%lld%lld", &xy[i].a, &xy[i].b);
		// scanf("%lld%lld%lld", &tup[i].a, &tup[i].b, &tup[i].c);
		scanf("%lld", &a[i]);
		// scanf("%lld", &b[i]);
		// scanf("%lld", &c[i]);
		// scanf("%lld", &d[i]);
		// a[i]--;
		// b[i]--;
		// c[i]--;
		// d[i]--;
		// xy[i].a--;
		// xy[i].b--;
		// tup[i].a--;
		// tup[i].b--;
	}
	// for (i = 0; i < m; i++) {
	// 	scanf("%lld%lld", &a[i], &b[i]);
	// 	a[i]--;
	// 	b[i]--;
	// }

	// for (i = 0; i < q; i++) {
	// 	// scanf("%lld%lld", &xy[i].a, &xy[i].b);
	// 	scanf("%lld", &c[i]);
	// 	// xy[i].a--;
	// 	// xy[i].b--;
	// }

	// for (i = 0; i < n; i++) {
	// 	for (j = 0; j < m; j++) {
	// 		scanf("%lld", &table[i][j]);
	// 		// table[i][j]--;
	// 	}
	// }
	// for (i = 0; i < h; i++) {
	// 	scanf("%s", s[i]);
	// }
	// scanf("%llu", &q);

	solve();

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:420:8: warning: format ‘%llu’ expects argument of type ‘long long unsigned int *’, but argument 2 has type ‘ull * {aka long unsigned int *}’ [-Wformat=]
  scanf("%llu", &n, &m);
        ^
./Main.c:420:8: warning: too many arguments for format [-Wformat-extra-args]
./Main.c:421:8: warning: format ‘%llu’ expects argument of type ‘long long unsigned int *’, but argument 2 has type ‘ull * {aka long unsigned int *}’ [-Wformat=]
  scanf("%llu", &k, &n, &m);
        ^
./Main.c:421:8: warning: too many arguments for format [-Wformat-extra-args]
./Main.c:437:9: warning: format ‘%lld’ expects argument of type ‘long long int *’, but argument 2 has type ‘sll * {aka long int *}’ [-Wformat=]
   scanf("%lld", &a[i]);
         ^
./Main.c:420:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%llu", &n, &m);
  ^
./Main.c:421:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunus...