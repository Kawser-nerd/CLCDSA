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
ull c[N_MAX + 5];
ull d[N_MAX + 5];
sll e[N_MAX];
char s[N_MAX + 1];
// char s[3010][3010];
char t[N_MAX + 1];
// char t[3010][3010];
// char u[N_MAX + 1];
hwll xy[N_MAX + 5];
hwllc tup[N_MAX + 5];
sll table[3005][3005];
// here we go

ull deg[N_MAX];
ull acdeg[N_MAX];
sll next[N_MAX][2];
ull p[N_MAX], l = 0;

void make (ull a[], ull d[]) {
	sll i, j, ki;

	i = 0;
	ull curr = 0;
	for (j = 0; j < l; j++) {
		for (ki = 0; ki < d[j]; ki++) {
			a[i] = curr + 1 + ki;
			i++;
		}
		a[i] = curr;
		i++;

		curr += d[j] + 1;
	}
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

	if (n == 2) {
		puts("1 2");
		return 0;
	}
	if (n == 3) {
		puts("1 2 3");
		return 0;
	}

	for (i = 0; i < n - 1; i++) {
		deg[a[i]]++;
		deg[b[i]]++;
	}
	for (i = 0; i < n; i++) {
		if (deg[i] > 1) {
			l++;
		}
	}
	for (i = 0; i < n - 1; i++) {
		if (deg[a[i]] > 1 && deg[b[i]] > 1) {
			acdeg[a[i]]++;
			acdeg[b[i]]++;
		}
	}
	for (i = 0; i < n; i++) {
		if (acdeg[i] == 1) {
			p[0] = i;
			break;
		}
	}
	if (l == 1) {
		// 1 3 4 5 ... n-1 2 n
		printf("1 ");
		for (i = 3; i <= n - 1; i++) {
			printf("%lld ", i);
		}
		printf("2 %lld\n", n);
		return 0;
	}
	for (i = p[0] + 1; i < n; i++) {
		if (acdeg[i] == 1) {
			p[l - 1] = i;
			break;
		}
	}
	if (i == n) goto fail;
	for (i = 0; i < n; i++) {
		if (deg[i] == 1 || i == p[0] || i == p[l - 1]) continue;
		if (acdeg[i] != 2) goto fail;
	}
	for (i = 0; i < n; i++) {
		next[i][0] = -1;
	}
	for (i = 0; i < n - 1; i++) {
		if (deg[a[i]] > 1 && deg[b[i]] > 1) {
			next[a[i]][(next[a[i]][0] < 0) ? 0 : 1] = b[i];
			next[b[i]][(next[b[i]][0] < 0) ? 0 : 1] = a[i];
		}
	}
	// for (i = 0; i < n; i++) printf("%lld - %lld\n", next[i][0], next[i][1]);
	// 	printf("%lld ~~ %lld\n", p[0], p[l - 1]);
	for (i = 1; i < l - 1; i++) {
		p[i] = ((i == 1) ? 0 : p[i - 2]) ^ next[p[i - 1]][0] ^ next[p[i - 1]][1];
		// printf("%lld\n", p[i]);
	}
	// puts("!");
	// fflush(stdout);
	for (i = 0; i < l; i++) {
		d[i] = deg[p[i]] - 2;
	}
	for (i = l - 1; i >= 0; i--) {
		d[i + 1] = d[i];
	}
	l += 2;
	d[0] = d[l - 1] = 0;

	make(a, d);
	i = 0;
	j = l - 1;
	while (i < j) {
		d[i] ^= d[j];
		d[j] ^= d[i];
		d[i] ^= d[j];
		i++;
		j--;
	}
	make(b, d);

	bool isa = true;
	for (i = 0; i < n; i++) {
		if (a[i] < b[i]) {
			isa = true;
			break;
		}
		if (a[i] > b[i]) {
			isa = false;
			break;
		}
	}
	for (i = 0; i < n; i++) {
		printf("%llu%c", (isa ? a : b)[i] + 1, (i == n - 1 ? '\n' : ' '));
	}

	// printf("%lld\n", result);
	// printf("%.15lf\n", dresult);
	// puts(s);

	return 0;

	success:
	puts("YES");
	// puts("Yes");
	// printf("%llu\n", result);
	// puts("0");
	// puts("Yay!");
	return 0;

	fail:
	// puts("NO");
	// puts("No");
	// puts("0");
	puts("-1");
	// puts("-1 -1 -1");
	// puts("Impossible");
	return 1;
}

int32_t main (void) {
	int32_t i, j;
	int32_t x, y;



	// scanf("%llu%llu", &h, &w);
	scanf("%llu", &n, &m);
	// scanf("%llu%llu", &k, &n, &m);
	// scanf("%llu%llu", &h, &w);
	// scanf("%llu", &q);
	// scanf("%s", s);
	// scanf("%lld%lld", &va, &vb, &vc, &vd);
	// scanf("%llu%llu%llu", &ua, &ub, &uc, &ud);
	// scanf("%s", t);
	// scanf("%lld", &m);
	for (i = 0; i < n - 1; i++) {
		// scanf("%lld%lld", &xy[i].a, &xy[i].b);
		// scanf("%lld%lld%lld", &tup[i].a, &tup[i].b, &tup[i].c);
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
	// scanf("%llu", &m, &k);
	// scanf("%llu", &q);
	// scanf("%s", s);
	// for (i = 0; i < n * 2; i++) {
	// 	scanf("%lld", &b[i]);
	// 	// b[i]--;
	// 	// c[i]--;
	// }
	// scanf("%llu", &q);

	// for (i = 0; i < q; i++) {
	// 	scanf("%lld%lld", &xy[i].a, &xy[i].b);
	// 	xy[i].a--;
	// 	xy[i].b--;
	// }

	// for (i = 0; i < h; i++) {
	// 	for (j = 0; j < w; j++) {
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
} ./Main.c: In function ‘solve’:
./Main.c:338:11: warning: format ‘%lld’ expects argument of type ‘long long int’, but argument 2 has type ‘sll {aka long int}’ [-Wformat=]
    printf("%lld ", i);
           ^
./Main.c:340:10: warning: format ‘%lld’ expects argument of type ‘long long int’, but argument 2 has type ‘ull {aka long unsigned int}’ [-Wformat=]
   printf("2 %lld\n", n);
          ^
./Main.c:404:10: warning: format ‘%llu’ expects argument of type ‘long long unsigned int’, but argument 2 has type ‘sll {aka long int}’ [-Wformat=]
   printf("%llu%c", (isa ? a : b)[i] + 1, (i == n - 1 ? '\n' : ' '));
          ^
./Main.c: In function ‘main’:
./Main.c:438:8: warning: format ‘%llu’ expects argument of type ‘long long unsigned int *’, but argument 2 has type ‘ull * {aka long unsigned int *}’ [-Wformat=]
  scanf("%llu", &n, &m);
        ^
./Main.c:438:8: warning: too many arguments for format [-Wformat-extra-args]
./Main.c:450:9: warning: format ‘%lld’ expects argument of type ‘long long int *’, but argume...