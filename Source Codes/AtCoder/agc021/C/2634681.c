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
#define FOD  998244353
typedef uint64_t ull;
typedef  int64_t sll;

#define N_MAX 300000
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
bool uf_union (ull a, ull b) {
	a = uf_find(a);
	b = uf_find(b);
	if (a == b) return false;

	if (rank[a] > rank[b]) {
		parent[b] = a;
	} else {
		parent[a] = b;
		if (rank[a] == rank[b]) {
			rank[b]++;
		}
	}
	return true;
}


sll a[N_MAX];
// sll a[3001][3001];
sll b[N_MAX];
sll c[N_MAX];
// char s[N_MAX + 1];
char s[3010][3010];
char t[N_MAX + 1];

void setA (ull i, ull j) {
	s[i][j] = '^';
	s[i + 1][j] = 'v';
}

void setB (ull i, ull j) {
	s[i][j] = '<';
	s[i][j + 1] = '>';
}

bool evev () {

	sll i, j;
	ull fa = 0, fb = 0;
	for (i = 0; i < h / 2; i++) {
		for (j = 0; j < w / 2; j++) {
			if (fa == n && fb == m) {
				break;
			}
			if (fa < n) {
				setA(i * 2, j * 2);
				if (++fa < n) {
					setA(i * 2, j * 2 + 1);
					fa++;
				}
			} else {
				setB(i * 2, j * 2);
				if (++fb < m) {
					setB(i * 2 + 1, j * 2);
					fb++;
				}
			}
		}
	}

	return (fa == n && fb == m);
}

bool odev () {

	sll i, j;
	ull fa = 0, fb = 0;
	for (i = 0; i < h / 2; i++) {
		for (j = 0; j < w / 2; j++) {
			if (fa == n && fb == m) break;

			if (fa < n) {
				setA(i * 2, j * 2);
				if (++fa < n) {
					setA(i * 2, j * 2 + 1);
					fa++;
				}
			} else {
				setB(i * 2, j * 2);
				if (++fb < m) {
					setB(i * 2 + 1, j * 2);
					fb++;
				}
			}
		}
	}
	if (fa < n) return false;
	for (j = 0; j < w / 2; j++) {
		if (fb == m) break;
		setB(h - 1, j * 2);
		fb++;
	}
	return (fb == m);
}

bool evod () {

	sll i, j;
	ull fa = 0, fb = 0;
	for (i = 0; i < h / 2; i++) {
		for (j = 0; j < w / 2; j++) {
			if (fa == n && fb == m) break;

			if (fb < m) {
				setB(i * 2, j * 2);
				if (++fb < m) {
					setB(i * 2 + 1, j * 2);
					fb++;
				}
			} else {
				setA(i * 2, j * 2);
				if (++fa < n) {
					setA(i * 2, j * 2 + 1);
					fa++;
				}
			}
		}
	}
	if (fb < m) return false;
	for (i = 0; i < h / 2; i++) {
		if (fa == n) break;
		setA(i * 2, w - 1);
		fa++;
	}
	return (fa == n);
}

bool odod () {
	sll i, j;
	ull fa = 0, fb = 0;

	for (i = 1; i < h; i += 2) {
		if (fa == n) break;
		setA(i, 0);
		fa++;
	}
	for (j = 1; j < w; j += 2) {
		if (fb == m) break;
		setB(h - 1, j);
		fb++;
	}

	if ((n - fa) + (m - fb) > 2 * (h / 2) * (w / 2)) return false;

	for (i = 0; i < h / 2; i++) {
		for (j = 0; j < w / 2; j++) {
			if (fa == n && fb == m) break;
			if (i == 0 && j == 0) {
				if ((n - fa) % 2 == 1 && (m - fb) % 2 == 1) {
					setB(0, 0);
					setA(0, 2);
					fa++;
					fb++;
					continue;
				}
			}

			if (fa < n) {
				setA(i * 2, j * 2 + 1);
				if (++fa < n) {
					setA(i * 2, j * 2 + 2);
					fa++;
				}
			} else {
				setB(i * 2, j * 2 + 1);
				if (++fb < m) {
					setB(i * 2 + 1, j * 2 + 1);
					fb++;
				}
			}
		}
	}

	return (fa == n && fb == m);
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

	n ^= (m ^= (n ^= m));

	for (i = 0; i < h; i++) {
		for (j = 0; j < w; j++) {
			s[i][j] = '.';
		}
	}

	if (n > (h / 2) * w || m > h * (w / 2) || n + m > h * w / 2) goto fail;

	bool isok;
	switch ((h % 2) * 2 + (w % 2)) {
	case 0:
		isok = evev();
		break;
	case 1:
		isok = evod();
		break;
	case 2:
		isok = odev();
		break;
	case 3:
		isok = odod();
		break;
	}

	if (isok) {
		puts("YES");
		for (i = 0; i < h; i++) {
			puts(s[i]);
		}
	} else {
		goto fail;
	}

	// printf("%lld\n", result);
	// printf("%.12lf\n", dresult);
	// puts(s);

	return 0;

	success:
	puts("YES");
	// puts("Yes");
	// printf("%llu\n", result);
	// puts("0");
	// puts("Takahashi");
	return 0;

	fail:
	puts("NO");
	// puts("No");
	// puts("0");
	// puts("-1");
	// puts("-1 -1 -1");
	// puts("Aoki");
	return 1;
}

int32_t main (void) {
	int32_t i, j;
	int32_t x, y;

	// scanf("%lf%lf", &vda, &vdb, &vdc);
	// scanf("%lld%lld", &vsa, &vsb, &vsc, &vsd);
	// scanf("%llu%llu", &vua, &vub, &vuc, &vud);
	// scanf("%*llu%*llu");
	scanf("%llu%llu", &h, &w);
	scanf("%llu%llu", &n, &m);
	// scanf("%llu", &k, &n);
	// scanf("%llu%llu%llu%llu", &vua, &vub, &vuc, &vud, &vue, &vuf);
	// vua--;
	// vub--;
	// vuc--;
	// vud--;
	// scanf("%lld%lld", &vsa, &vsb, &vsc);
	// scanf("%s", s);
	// scanf("%s", t);
	// scanf("%llu", &k);
	// scanf("%llu", &q);
	// for (i = 0; i < n; i++) {
	// 	scanf("%lld", &a[i]);
	// 	scanf("%lld", &b[i]);
	// 	// scanf("%llu", &c[i]);
	// 	// a[i]--;
	// 	// b[i]--;
	// 	// c[i]--;
	// }
	// for (i = 0; i < m; i++) {
	// 	scanf("%llu", &b[i]);
	// }
	// scanf("%llu", &q);

	// for (i = 0; i < n; i++) {
	// 	for (j = 0; j < n; j++) {
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
./Main.c:142:9: warning: format ‘%llu’ expects argument of type ‘long long unsigned int’, but argument 2 has type ‘ull {aka long unsigned int}’ [-Wformat=]
  printf("%llu.", left / right);
         ^
./Main.c:146:10: warning: format ‘%d’ expects argument of type ‘int’, but argument 2 has type ‘ull {aka long unsigned int}’ [-Wformat=]
   printf("%1d", left / right);
          ^
./Main.c: In function ‘main’:
./Main.c:543:8: warning: format ‘%llu’ expects argument of type ‘long long unsigned int *’, but argument 2 has type ‘ull * {aka long unsigned int *}’ [-Wformat=]
  scanf("%llu%llu", &h, &w);
        ^
./Main.c:543:8: warning: format ‘%llu’ expects argument of type ‘long long unsigned int *’, but argument 3 has type ‘ull * {aka long unsigned int *}’ [-Wformat=]
./Main.c:544:8: warning: format ‘%llu’ expects argument of type ‘long long unsigned int *’, but argument 2 has type ‘ull * {aka long unsigned int *}’ [-Wformat=]
  scanf("%llu%llu", &n, &m);
        ^
./Main...