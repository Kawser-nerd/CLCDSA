/*
cat <<EOF >mistaken-paste
*/

#pragma GCC diagnostic ignored "-Wincompatible-pointer-types"

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#define BIG 2000000007
#define VERYBIG 200000000000007LL

#define MOD 1000000007
typedef uint64_t ull;
typedef  int64_t sll;

#define N_MAX 20
#define M_MAX 200000

#ifdef __cplusplus
#include <queue>
#include <stack>
// #include <tuple>

using namespace std; // I'm NOT gonna use C++ without compro. shit

typedef priority_queue<ull, vector<ull>, greater<ull> > upque123;
typedef priority_queue<ull, vector<ull> > upque321;
typedef priority_queue<sll, vector<sll>, greater<sll> > spque123;
typedef priority_queue<sll, vector<sll> > spque321;

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

sll nibutanlobo (bool (*func)(sll arg), sll ok, sll ng) {
	while (sllabs(ok, ng) > 1) {
		sll med = (ok + ng) / 2;
		if (func(med)) {
			ok = med;
		} else {
			ng = med;
		}

		// printf("debug: [%lld %lld)\n", ok, ng);
	}

	if (!func(ok)) return ok * 2 - ng;
	return ok;
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
	printUquotient(sllabs(left, 0), sllabs(right, 0));

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

typedef struct {
	int32_t to;
	sll cost;
} edge;
typedef pair<sll, int32_t> P;

std::vector<edge> g[N_MAX];
void dijk_init (ull n, struct_b arr[]) {
	edge x;
	for (int32_t i = 0; i < n; i++) {
		x.to = arr[i].to;
		x.cost = arr[i].cost;
		g[arr[i].from].push_back(x);
	}
}

bool dijkstra (int s, sll distance[]) {
	priority_queue<P, std::vector<P>, greater<P> > que; // (????, ????)
	que.push(P(distance[s], s));

	bool ischanged = false;
	while (!que.empty()) {
		P p = que.top();
		que.pop();

		sll v = p.second;
		if (distance[v] < p.first) continue;

		int32_t maxsize = g[v].size();
		for (int32_t i = 0; i < maxsize; i++) {
			edge e = g[v][i];
			if (distance[e.to] > distance[v] + e.cost) {
				distance[e.to] = distance[v] + e.cost;
				ischanged = true;
				que.push(P(distance[e.to], e.to));
			}
		}
	}

	return ischanged;
}

#endif

sll dist[N_MAX];
struct_b path[M_MAX * 2];

// ull a[N_MAX];
// ull a[M_MAX];
// sll a[N_MAX];
ull a[N_MAX][N_MAX];
// sll a[N_MAX][N_MAX];
ull b[N_MAX];
// ull b[M_MAX];
// sll b[N_MAX];
// ull c[N_MAX];
// sll c[M_MAX];
// char c[N_MAX];
// char s[N_MAX + 1];
// char s[N_MAX + 1][N_MAX + 1];
// char s[N_MAX + 1][M_MAX + 1];
// char t[N_MAX + 1];

// ull alphabets[26];
// char alphabets[26];

// ull dp[N_MAX + 1];
// sll dp[N_MAX + 1];
// ull dp[N_MAX + 1][N_MAX + 1];
// sll dp[N_MAX + 1][N_MAX + 1];
// bool dp[N_MAX + 1];
// bool dp[N_MAX + 1][N_MAX + 1];
// hwll arr[N_MAX];
// hwll arr[M_MAX];

// typedef tuple<sll, int32_t, int32_t> P2d;

ull bitdp[16][16][1 << 16];
ull bitroute[1 << 16];

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

int32_t pbitdpcomp (const void *left, const void *right) {
	ull l = *(ull*)left;
	ull r = *(ull*)right;

	int32_t bitsc = (bitcount(l) - bitcount(r));
	if (bitsc < 0) {
		return -1;
	} else if (bitsc > 0) {
		return +1;
	} else if (l < r) {
		return -1;
	} else if (l > r) {
		return +1;
	} else {
		return 0;
	}
}

ull matrixmulti (ull x[16][16], const ull y[16][16]) {
	ull data[16][16];
	sll i, j, ki;
	for (i = 0; i < m; i++) {
		for (j = 0; j < m; j++) {
			data[i][j] = 0;
			for (ki = 0; ki < m; ki++) {
				data[i][j] = (data[i][j] + x[i][ki] * y[ki][j]) % MOD;
			}
		}
	}
	for (i = 0; i < m; i++) {
		for (j = 0; j < m; j++) {
			x[i][j] = data[i][j];
		}
	}

	return m;
}

bool fuck (sll c1, sll c2, sll r, sll p1, sll p2) {
	return (((p1 - c1) * (p1 - c1) + (p2 - c2) * (p2 - c2)) <= r * r);
}

ull solve () {
	sll x1, y1, r;
	sll x2, y2, x3, y3;

	scanf("%lld%lld%lld", &x1, &y1, &r);
	scanf("%lld%lld%lld%lld", &x2, &y2, &x3, &y3);

	if (x1 - r >= x2 && x1 + r <= x3 && y1 - r >= y2 && y1 + r <= y3) {
		puts("NO");
	} else {
		puts("YES");
	}
	if (fuck(x1, y1, r, x2, y2) && 
		fuck(x1, y1, r, x2, y3) && 
		fuck(x1, y1, r, x3, y2) && 
		fuck(x1, y1, r, x3, y3)) {
		if (fuck(x1, y1, r, x2, y2)) {
			// puts("1");
		}
		if (fuck(x1, y1, r, x2, y3)) {
			// puts("2");
		}
		if (fuck(x1, y1, r, x3, y2)) {
			// puts("3");
		}
		if (fuck(x1, y1, r, x3, y3)) {
			// puts("4");
		}
		puts("NO");
	} else {
		puts("YES");
	}
	return 0;
}

int32_t main (void) {
	int32_t i, j;
	int32_t x, y;

	solve();

	return 0;
} ./Main.c: In function ‘printUquotient’:
./Main.c:187:9: warning: format ‘%llu’ expects argument of type ‘long long unsigned int’, but argument 2 has type ‘ull {aka long unsigned int}’ [-Wformat=]
  printf("%llu.", left / right);
         ^
./Main.c:191:10: warning: format ‘%d’ expects argument of type ‘int’, but argument 2 has type ‘ull {aka long unsigned int}’ [-Wformat=]
   printf("%1d", left / right);
          ^
./Main.c: In function ‘solve’:
./Main.c:381:8: warning: format ‘%lld’ expects argument of type ‘long long int *’, but argument 2 has type ‘sll * {aka long int *}’ [-Wformat=]
  scanf("%lld%lld%lld", &x1, &y1, &r);
        ^
./Main.c:381:8: warning: format ‘%lld’ expects argument of type ‘long long int *’, but argument 3 has type ‘sll * {aka long int *}’ [-Wformat=]
./Main.c:381:8: warning: format ‘%lld’ expects argument of type ‘long long int *’, but argument 4 has type ‘sll * {aka long int *}’ [-Wformat=]
./Main.c:382:8: warning: format ‘%lld’ expects argument of type ‘long long int *’, but ar...