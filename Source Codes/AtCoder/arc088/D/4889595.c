#if 0
cat <<EOF >mistaken-paste
#endif
// thx Ebi-chan!

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

#define N_MAX 1048576

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

typedef struct {
	double a;
	double b;
} hwreal;

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
	DEFLR(sll);
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
BEGCMP(phwrealcomp){
	DEFLR(hwreal);
	CMPRET(l.a, r.a);
	CMPRET(l.b, r.b);
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
// char s[N_MAX + 1];
char s[3010][3010];
char t[N_MAX + 1];
// char t[3010][3010];
char u[N_MAX + 1];
hwll xy[N_MAX + 5];
hwllc tup[N_MAX + 5];
// sll table[3005][3005];
ull gin[N_MAX];
// here we go

ull st[N_MAX];
ull r = 0;
bool isok;
sll dfs (ull v, ull p, ull start, ull var) {
	ull len = 0;
	sll i;
	if (d[v] % 2) {
		st[start + len++] = 0;
	}
	for (i = gin[v]; i < gin[v + 1]; i++) {
		ull u = xy[i].b;
		if (u == p) continue;

		sll x = dfs(u, v, start + len, var);
		if (x == -1) return -1;

		x++;
		st[start + len++] = x;
		// printf("has %lld\n", x);
	}
	qsort(st + start, len, sizeof(sll), psllcomp);

	// printf("%llu; ", v);
	// for (i = 0; i < len; i++) {
	// 	printf("%lld ", st[start + i]);
	// }
	// puts("");

	// for (sll i = len - 1; i > 0; i -= 2) {
	// 	ull cand = st[start + i] + st[start + i - 1];
	// 	r = umax(r, cand);
	// }
	ull l = (len & ~1LL);
	for (i = 0; i < l / 2; i++) {
		if (st[start + i] + st[start + (l - 1 - i)] > var) {
			isok = false;
			return -1;
		}
	}
	sll ok = len - 1, ng = -1;
	if (v) {
		while (ng + 1 < ok) {
			sll med = (ok + ng) / 2;
			for (i = 0; i < l / 2; i++) {
				sll left = i, right = (l - 1 - i);
				if (left >= med) left++;
				if (right >= med) right++;

				if (st[start + left] + st[start + right] > var) break;
			}

			if (i == l / 2) {
				ok = med;
			} else {
				ng = med;
			}
		}
	}
	// printf("ok: %lld -> %lld\n", ok, st[start + ok]);

	return st[start + ok];
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
	sll *dpcell;

	for (i = 0; i < n - 1; i++) {
		xy[i] = (hwll){a[i], b[i]};
		xy[i + (n - 1)] = (hwll){b[i], a[i]};
	}
	qsort(xy, (n - 1) * 2, sizeof(hwll), phwllABcomp);
	i = j = 0;
	while (i <= n) {
		gin[i] = j;
		while (j < (n - 1) * 2 && xy[j].a == i) j++;
		i++;
	}

	ull odds = 0;
	for (i = 0; i < n - 1; i++) {
		d[a[i]]++;
		d[b[i]]++;
	}
	for (i = 0; i < n; i++) {
		if (d[i] % 2) odds++;
	}

	sll ok = n, ng = 0;
	while (ng + 1 < ok) {
		sll med = (ok + ng) / 2;
		r = 0;
		isok = true;
		sll ret = dfs(0, n, 0, med);
		if (isok) {
			ok = med;
		} else {
			ng = med;
		}
	}
	result = ok;

	printf("%llu %llu\n", odds / 2, result);

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
	puts("No");
	// puts("0");
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
	// scanf("%llu", &k, &n, &m);
	// scanf("%llu%llu", &h, &w);
	// scanf("%llu", &q);
	// scanf("%s", s);
	// scanf("%lld%lld", &va, &vb, &vc, &vd);
	// scanf("%llu%llu%llu", &ua, &ub, &uc, &ud, &ue);
	// scanf("%s", t);
	// scanf("%s", u);
	// scanf("%llu", &k);
	// scanf("%lld", &m);
	// for (i = 0; i < n; i++) {
	// 	scanf("%lld", &a[i]);
	// 	// scanf("%lld", &d[i]);
	// }
	// scanf("%llu", &q);
	for (i = 0; i < n - 1; i++) {
		// scanf("%lld%lld", &xy[i].a, &xy[i].b);
		// scanf("%lld%lld%lld", &tup[i].a, &tup[i].b, &tup[i].c);
		// scanf("%lld", &c[i]);

		scanf("%lld", &a[i]);
		scanf("%lld", &b[i]);
		// scanf("%lld", &c[i]);
		// scanf("%lld", &d[i]);
		a[i]--;
		b[i]--;
		// c[i]--;
		// d[i]--;
		// xy[i].a--;
		// xy[i].b--;
		// tup[i].a--;
		// tup[i].b--;
	}
	// for (i = 0; i < k; i++) {
	// 	// scanf("%lld%lld", &a[i], &b[i]);
	// 	// scanf("%lld", &b[i]);
	// 	// a[i]--;
	// 	// b[i]--;
	// 	scanf("%lld", &d[i]);
	// 	d[i]--;
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
	// for (i = 0; i < n; i++) {
	// 	scanf("%s", s[i]);
	// }
	// scanf("%llu", &q);

	solve();

	return 0;
} ./Main.c: In function ‘solve’:
./Main.c:387:9: warning: format ‘%llu’ expects argument of type ‘long long unsigned int’, but argument 2 has type ‘ull {aka long unsigned int}’ [-Wformat=]
  printf("%llu %llu\n", odds / 2, result);
         ^
./Main.c:387:9: warning: format ‘%llu’ expects argument of type ‘long long unsigned int’, but argument 3 has type ‘sll {aka long int}’ [-Wformat=]
./Main.c: In function ‘main’:
./Main.c:420:8: warning: format ‘%llu’ expects argument of type ‘long long unsigned int *’, but argument 2 has type ‘ull * {aka long unsigned int *}’ [-Wformat=]
  scanf("%llu", &n, &m);
        ^
./Main.c:420:8: warning: too many arguments for format [-Wformat-extra-args]
./Main.c:441:9: warning: format ‘%lld’ expects argument of type ‘long long int *’, but argument 2 has type ‘sll * {aka long int *}’ [-Wformat=]
   scanf("%lld", &a[i]);
         ^
./Main.c:442:9: warning: format ‘%lld’ expects argument of type ‘long long int *’, but argument 2 has type ‘sll * {aka long int *}’ [-Wformat=]
   sc...