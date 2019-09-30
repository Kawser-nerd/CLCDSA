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

#define N_MAX 1000
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

sll dist[N_MAX];
struct_b path[M_MAX * 2];

// ull a[N_MAX];
// ull a[M_MAX];
sll a[N_MAX];
// ull a[N_MAX][N_MAX];
// ull a[M_MAX][M_MAX];
// sll a[N_MAX][N_MAX];
// ull b[N_MAX];
// ull b[M_MAX];
sll b[N_MAX];
ull c[N_MAX];
// sll c[M_MAX];
// char c[N_MAX];
// char s[N_MAX + 1];
char s[N_MAX + 1][N_MAX + 1];
// char s[N_MAX + 1][M_MAX + 1];
// char t[N_MAX + 1];

ull alphabets[26];
// ull blphabets[26];
// char alphabets[26];

// ull dp[N_MAX + 1];
// sll dp[N_MAX + 1];
// ull dp[N_MAX + 1][N_MAX + 1];
// sll dp[N_MAX + 1][N_MAX + 1];
// bool dp[N_MAX + 1];
// bool dp[N_MAX + 1][N_MAX + 1];
// bool dq[N_MAX];
hwll arr[N_MAX + 1];
// hwll arr[M_MAX];
hwll brr[N_MAX];

// sll dp[N_MAX + 1];
// ull color[N_MAX];
// set<sll> children[N_MAX];
// set<sll> leaf[N_MAX];



double distance (sll x1, sll y1, sll x2, sll y2) {
	double xdist2, ydist2, origindist, dist;

	xdist2 = (x1 - x2) * (x1 - x2);
	ydist2 = (y1 - y2) * (y1 - y2);
	return sqrt(xdist2 + ydist2);
}

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
	ull l = *(sll*)left;
	ull r = *(sll*)right;
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

ull accp (ull a, ull p) {
	if (a == 0) {
		return 0;
	}
	if (a == 1) {
		return p;
	}

	return divide((MOD + bitpow(a, p, MOD) - 1) % MOD, a - 1, MOD);
}

sll dd (sll t, sll x) {
	if (x < t) {
		if ((t - x) % 2) return BIG;
		return (t - x) / 2;
	} else {
		return (x - t);
	}
}

bool func (double x) {
	sll i, j;
	for (i = 0; i < n + m; i++) {
		for (j = i + 1; j < n + m; j++) {
			if (i < n) {
				if (x > (double)c[i]) return false;
			}

			double rsum = (i < n ? (double)c[i] : x) + (j < n ? (double)c[j] : x);
			double actualdist = distance(a[i], b[i], a[j], b[j]);

			if (rsum > actualdist) return false;
		}
	}

	return true;
}

bool isinrange (sll left, sll x, sll right) {
	return (left <= x && x <= right);
}

ull frac[2000000];
ull dp[2000000];

	ull d[1000][1000];
ull solve () {
	sll i, j, ki, li;
	ull result = 0;
	// sll result = 0;
	// double result = 0;
	// ull maybe = 0;
	sll maybe = 0;
	// ull sum = 0;
	sll sum = 0;
	ull item;
	ull *dpcell;

	for (i = 0; i <= n + 10; i++) {
		if (i == 0) {
			frac[i] = 1;
		} else {
			frac[i] = (frac[i - 1] * i) % MOD;
		}
	}

	for (i = 1; i < n; i++) {
		if (i < n - i) {
			dp[i] = 0;
		} else {
			// dp[i] = divide(1, frac[n - i], MOD);
			// dp[i] = divide(divide(frac[i], frac[n - i], MOD), frac[i * 2 - n], MOD);
			dp[i] = divide(divide(frac[i - 1], frac[n - i - 1], MOD), frac[i * 2 - n], MOD);
		}
		// printf("[%llu][%llu]: %llu\n", n, i, dp[i]);
	}

	for (i = 1; i < n; i++) {
		ull coveri = (frac[i] * dp[i] % MOD) * frac[(n - 1) - i] % MOD;
		ull coveri1 = (frac[i - 1] * dp[i - 1] % MOD) * frac[(n - 1) - (i - 1)] % MOD;
		// ull yet = frac[n - i];

		ull item = ((MOD + coveri - coveri1) % MOD) % MOD;
		// ull item = (MOD + (coveri % MOD) - (coveri1 % MOD)) % MOD;
		// item = (((MOD + (frac[i] * dp[i] % MOD) - (frac[i - 1] * dp[i - 1] % MOD)) % MOD) * frac[n - i] % MOD);
		result = (result + (item * i) % MOD) % MOD;
		// printf("%lld: %llu...\n", i, result);
	}


	// for (i = 0; i < 1000; i++) {
	// 	// printf("%2llu:", i);
	// 	for (j = 0; j < 1000; j++) {
	// 		if (i == 0) {
	// 			d[i][j] = (j ? 0 : 1);
	// 			continue;
	// 		}
	// 		if (i == 1) {
	// 			d[i][j] = 0;
	// 			continue;
	// 		}

	// 		d[i][j] = (i > 0 ? d[i - 1][j - 1] : 0) + (i > 1 ? d[i - 2][j - 1] : 0);
	// 		d[i][j] %= MOD;
	// 		// printf("%4llu ", dp[i][j]);
	// 	}
	// 	// puts("");
	// }
	// for (i = 1; i < n; i++) {
	// 	if (dp[i] != d[n][i]) {
	// 		printf("[%llu][%llu] %llu != %llu\n", n, i, d[n][i], dp[i]);
	// 	}
	// }


	printf("%lld\n", result);
	// printf("%.12lf\n", (double)result);
	// puts(s);

	return 0;

	success:
	puts("YES");
	// puts("Yes");
	// printf("%llu\n", result);
	// puts("0");
	// puts("First");
	return 0;

	fail:
	puts("NO");
	// puts("No");
	// puts("0");
	// puts("-1");
	// puts("-1 -1 -1");
	// puts("Second");
	return 1;
}

int32_t main (void) {
	int32_t i, j;
	int32_t x, y;

	// scanf("%lf", &vda, &vdb);
	// scanf("%lld%lld%lld%lld", &vsa, &vsb, &vsc, &vsd);
	// scanf("%llu%llu", &vua, &vub, &vuc, &vud);
	// scanf("%llu%llu", &h, &w);
	// scanf("%*llu%*llu");
	scanf("%llu", &n, &m);
	// scanf("%llu", &k, &n);
	// scanf("%llu%llu", &vua, &vub, &vuc, &vud, &vue, &vuf);
	// scanf("%lld%lld", &vsa, &vsb, &vsc);
	// scanf("%s", s);
	// scanf("%s", t);
	// scanf("%llu", &m);
	// scanf("%llu", &q);
	// for (i = 0; i < n; i++) {
	// 	scanf("%lld", &a[i]);
	// 	// scanf("%lld", &b[i]);
	// 	// scanf("%llu", &c[i]);
	// 	// a[i]--;
	// 	// b[i]--;
	// }
	// for (i = 0; i < m; i++) {
	// 	scanf("%lld", &a[n + i]);
	// 	scanf("%lld", &b[n + i]);
	// }
	// for (i = 0; i < n; i++) {
	// 	scanf("%llu", &b[i]);
	// }
	// for (i = 0; i < h; i++) {
	// 	for (j = 0; j < w; j++) {
	// 		scanf("%llu", &a[i][j]);
	// 	}
	// }
	// for (i = 0; i < n; i++) {
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
./Main.c:423:9: warning: format ‘%lld’ expects argument of type ‘long long int’, but argument 2 has type ‘ull {aka long unsigned int}’ [-Wformat=]
  printf("%lld\n", result);
         ^
./Main.c: In function ‘main’:
./Main.c:456:8: warning: format ‘%llu’ expects argument of type ‘long long unsigned int *’, but argument 2 has type ‘ull * {aka long unsigned int *}’ [-Wformat=]
  scanf("%llu", &n, &m);
        ^
./Main.c:456:8: warning: too many arguments for format [-Wformat-extra-args]
./Main.c:456:2: warning: ignoring return value of ‘scanf’, declared with attrib...