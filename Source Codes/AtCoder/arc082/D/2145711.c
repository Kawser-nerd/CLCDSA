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

void swap_adj (ull *a, ull *b) {
	if (*a != *b) {
		ull tmp = *b;
		*b = *a;
		*a = tmp;
	}
	return;
}

int32_t digits (ull x) {
	int32_t i = 1;
	while (x >= 10) {
		x /= 10;
		i++;
	}
	return i;
}

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

ull ullabs (ull a, ull b) {
	if (a >= b) {
		return a - b;
	} else {
		return b - a;
	}
}

sll sllabs (sll a, sll b) {
	if (a >= b) {
		return a - b;
	} else {
		return b - a;
	}
}


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
// ull c[N_MAX];
sll c[M_MAX];
// char c[N_MAX];
// char s[N_MAX + 1];
// char s[N_MAX + 1][N_MAX + 1];
// char s[N_MAX + 1][M_MAX + 1];
// char t[N_MAX + 1];

// ull alphabets[26];
// ull blphabets[26];
// char alphabets[26];

// ull dp[N_MAX + 1];
// sll dp[N_MAX + 1];
// ull dp[N_MAX + 1][N_MAX + 1];
// sll dp[N_MAX + 1][N_MAX + 1];
// bool dp[N_MAX + 1];
// bool dp[N_MAX + 1][N_MAX + 1];
hwll arr[N_MAX + 1];
// hwll arr[M_MAX];
// hwll brr[M_MAX];

// sll dp[N_MAX + 1];
// ull color[N_MAX];
// set<sll> children[N_MAX];
// set<sll> leaf[N_MAX];

// bool redfill[N_MAX];

typedef struct {
	hwll min;
	hwll max;
} linedpll;

linedpll minmax[N_MAX + 1];

ull solve () {
	sll i, j, ki;
	// ull result = 0;
	sll result = 0;
	// double result = 0;
	ull maybe = 0;
	// sll maybe = 0;
	// ull sum = 0;
	sll sum = 0;
	ull item;
	ull *dpcell;


	linedpll initial = {{0, 0}, {k, k}};
	minmax[0] = initial;

	for (i = 0; i < n; i++) {
		bool isdecre = (i % 2 == 0);
		ull time = a[i] - (i ? a[i - 1] : 0);

		if (isdecre) {
			if (minmax[i].min.b >= time) {
				minmax[i + 1] = minmax[i];
				minmax[i + 1].min.b -= time;
				minmax[i + 1].max.b -= time;
			} else if (minmax[i].max.b < time) {
				linedpll x = {{0, 0}, {0, 0}};
				minmax[i + 1] = x;
			} else {
				sll pilled = time - minmax[i].min.b;

				minmax[i + 1] = minmax[i];
				minmax[i + 1].max.b -= time;

				minmax[i + 1].min.a += pilled;
				minmax[i + 1].min.b = 0;
			}
		} else {
			if (minmax[i].max.b <= k - time) {
				minmax[i + 1] = minmax[i];
				minmax[i + 1].min.b += time;
				minmax[i + 1].max.b += time;
			} else if (minmax[i].min.b > k - time) {
				linedpll x = {{k, k}, {k, k}};
				minmax[i + 1] = x;
			} else {
				sll pilled = minmax[i].max.b - (k - time);

				minmax[i + 1] = minmax[i];
				minmax[i + 1].min.b += time;

				minmax[i + 1].max.a -= pilled;
				minmax[i + 1].max.b = k;
			}
		}

		minmax[i + 1].min.a = smin(smax(minmax[i + 1].min.a, 0), k);
		minmax[i + 1].min.b = smin(smax(minmax[i + 1].min.b, 0), k);
		minmax[i + 1].max.a = smin(smax(minmax[i + 1].max.a, 0), k);
		minmax[i + 1].max.b = smin(smax(minmax[i + 1].max.b, 0), k);

		// printf("%lld: ~%lld:%llu, %lld~: %llu\n", i + 1, minmax[i + 1].min.a, minmax[i + 1].min.b, minmax[i + 1].max.a, minmax[i + 1].max.b);
	}

	sll lastrev = 0;
	for (i = 0; i < q; i++) {
		while (lastrev < n && a[lastrev] <= arr[i].a) lastrev++;

		bool isdecre = (lastrev % 2 == 0);

		sll moret = arr[i].a - (lastrev ? a[lastrev - 1] : 0);
		if (isdecre) {
			sll pill;
			if (arr[i].b < minmax[lastrev].min.a) {
				pill = 0;
			} else {
				pill = smin(arr[i].b, minmax[lastrev].max.a) - minmax[lastrev].min.a;
			}
			// printf("[%lld, %lld]\n", lastrev, pill);

			result = smax(minmax[lastrev].min.b + pill - moret, 0);
		} else {
			sll pill;
			if (arr[i].b > minmax[lastrev].max.a) {
				pill = 0;
			} else {
				pill = minmax[lastrev].max.a - smax(arr[i].b, minmax[lastrev].min.a);
			}
			// printf("[%lld, %lld]\n", lastrev, pill);

			result = smin(minmax[lastrev].max.b - pill + moret, k);
		}

		printf("%lld\n", result);
	}

	return 0;
}

int32_t main (void) {
	int32_t i, j;
	int32_t x, y;

	scanf("%llu%llu", &k, &n);
	for (i = 0; i < n; i++) {
		scanf("%llu", &a[i]);
	}

	scanf("%llu", &q);
	for (i = 0; i < q; i++) {
		scanf("%llu%llu", &arr[i].a, &arr[i].b);
	}

	solve();

	return 0;
} ./Main.c: In function ‘solve’:
./Main.c:318:10: warning: format ‘%lld’ expects argument of type ‘long long int’, but argument 2 has type ‘sll {aka long int}’ [-Wformat=]
   printf("%lld\n", result);
          ^
./Main.c: In function ‘main’:
./Main.c:328:8: warning: format ‘%llu’ expects argument of type ‘long long unsigned int *’, but argument 2 has type ‘ull * {aka long unsigned int *}’ [-Wformat=]
  scanf("%llu%llu", &k, &n);
        ^
./Main.c:328:8: warning: format ‘%llu’ expects argument of type ‘long long unsigned int *’, but argument 3 has type ‘ull * {aka long unsigned int *}’ [-Wformat=]
./Main.c:330:9: warning: format ‘%llu’ expects argument of type ‘long long unsigned int *’, but argument 2 has type ‘sll * {aka long int *}’ [-Wformat=]
   scanf("%llu", &a[i]);
         ^
./Main.c:333:8: warning: format ‘%llu’ expects argument of type ‘long long unsigned int *’, but argument 2 has type ‘ull * {aka long unsigned int *}’ [-Wformat=]
  scanf("%llu", &q);
        ^
./Main.c:335:9: warning: format ‘%...