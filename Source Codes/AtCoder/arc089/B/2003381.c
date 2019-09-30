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

#define N_MAX 300000
#define M_MAX 100000

#ifdef __cplusplus
#include <queue>
#include <stack>

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

ull divide (ull a, ull b) {
	ull x = MOD - 2;
	ull ans = 1;
	while (x) {
		if (x & 1) ans = (ans * b) % MOD;
		b = (b * b) % MOD;
		x /= 2;
	}
	return (a * ans) % MOD;
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

int32_t targetdig (ull x, int32_t index /* 1-indexed */) {
	// static...?
	int32_t posmax = digits(x);
	if (posmax < index) return -1;
	while (posmax > index) {
		posmax--;
		x /= 10;
	}
	return x % 10;
}

int32_t charcomp (const char left, const char right) {
	if (left < right) {
		return -1;
	} else if (left > right) {
		return +1;
	} else {
		return 0;
	}
}

int32_t pcharcomp (const void *left, const void *right) {
	char lval = *(char*)left;
	char rval = *(char*)right;
	return charcomp(lval, rval);
}

int32_t intcomp (const int32_t left, const int32_t right) {
	if (left < right) {
		return -1;
	} else if (left > right) {
		return +1;
	} else {
		return 0;
	}
}

int32_t pintcomp (const void *left, const void *right) {
	int lval = *(int*)left;
	int rval = *(int*)right;
	return intcomp(lval, rval);
}

int32_t ullcomp (const ull left, const ull right) {
	if (left < right) {
		return -1;
	} else if (left > right) {
		return +1;
	} else {
		return 0;
	}
}

int32_t pullcomp (const void *left, const void *right) {
	ull lval = *(ull*)left;
	ull rval = *(ull*)right;
	return ullcomp(lval, rval);
}

int32_t pullrevcomp (const void *left, const void *right) {
	ull lval = *(ull*)left;
	ull rval = *(ull*)right;
	return -ullcomp(lval, rval);
}

int32_t sllcomp (const sll left, const sll right) {
	if (left < right) {
		return -1;
	} else if (left > right) {
		return +1;
	} else {
		return 0;
	}
}

int32_t psllcomp (const void *left, const void *right) {
	sll lval = *(sll*)left, rval = *(sll*)right;
	return ullcomp(lval, rval);
}

int32_t hwllfraccomp (const hwll left, const hwll right) {
	return ullcomp(left.a * right.b, left.b * right.a);
}

int32_t phwAcomp (const hw *left, const hw *right) {
	return intcomp(left->a, right->a);
}

int32_t phwBcomp (const hw *left, const hw *right) {
	return intcomp(left->b, right->b);
}

int32_t phwABcomp (const hw *left, const hw *right) {
	int32_t x = phwAcomp(left, right);
	if (x) return x;
	return phwBcomp(left, right);
}

int32_t phwllAcomp (const hwll *left, const hwll *right) {
	return sllcomp(left->a, right->a);
}

int32_t phwllBcomp (const hwll *left, const hwll *right) {
	return sllcomp(left->b, right->b);
}

int32_t phwllABcomp (const void *left, const void *right) {
	hwll lval = *(hwll*)left, rval = *(hwll*)right;
	int32_t x = sllcomp(lval.a, rval.a);
	if (x) return x;
	return sllcomp(lval.b, rval.b);
}

int32_t phwllrAcBcomp (const hwll *left, const hwll *right) {
	int32_t x = -phwllAcomp(left, right);
	if (x) return x;
	return phwllBcomp(left, right);
}

int32_t phwllBAcomp (const hwll *left, const hwll *right) {
	int32_t x = phwllBcomp(left, right);
	if (x) return x;
	return phwllAcomp(left, right);
}

int32_t pstrAcomp (const struct_a *left, const struct_a *right) {
	int32_t x;
	if (x = ullcomp(left->t, right->t)) return x;
	if (x = ullcomp(left->s, right->s)) return x;
	if (x = intcomp(left->c, right->c)) return x;
	return 0;
}

int32_t bitlet (char c) {
	return (1 << (c - 'a'));
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

bool nextrouteint (int32_t arr[], int32_t n) {
	int32_t i = n - 1;
	int32_t j, x;

	while (i > 0 && arr[i - 1] > arr[i]) i--;
	if (i == 0) return false;

	x = n;
	for (j = i; j < n; j++) {
		if (arr[j] < arr[i - 1]) continue;
		if (x == n || arr[x] > arr[j]) x = j;
	}
	arr[i - 1] ^= arr[x];
	arr[x] ^= arr[i - 1];
	arr[i - 1] ^= arr[x];

	qsort(&arr[i], n - i, sizeof(int32_t), pintcomp);
	return true;
}

bool nextrouteull (ull arr[], int32_t n) {
	int32_t i = n - 1;
	int32_t j, x;

	while (i > 0 && arr[i - 1] > arr[i]) i--;
	if (i == 0) return false;

	x = n;
	for (j = i; j < n; j++) {
		if (arr[j] < arr[i - 1]) continue;
		if (x == n || arr[x] > arr[j]) x = j;
	}
	arr[i - 1] ^= arr[x];
	arr[x] ^= arr[i - 1];
	arr[i - 1] ^= arr[x];

	qsort(&arr[i], n - i, sizeof(ull), pintcomp);
	return true;
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

void dijk_distinit (int s, sll distance[], ull n) {
	for (int32_t i = 0; i < n; i++) {
		distance[i] = BIG;
	}
	distance[s] = 0;
	return;
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
sll a[N_MAX];
// ull a[N_MAX][N_MAX];
ull b[N_MAX];
// sll b[N_MAX];
// ull c[N_MAX];
char c[N_MAX];
char s[N_MAX + 1];
char t[N_MAX + 1];

// ull alphabets[26];

// ull dp[N_MAX + 1];
// ull dp[N_MAX + 1][N_MAX + 1];
// bool dp[N_MAX + 1][N_MAX + 1];
// hwll arr[N_MAX];

sll imos[2001][2001];
sll imoslow[2001];

double distance (sll x1, sll y1, sll x2, sll y2) {
	double xdist2, ydist2, origindist, dist;

	xdist2 = (x1 - x2) * (x1 - x2);
	ydist2 = (y1 - y2) * (y1 - y2);
	return sqrt(xdist2 + ydist2);
}

ull solve () {
	sll i, j, ki, l;
	ull result = 0;
	// sll result = 0;
	// double result = 0;
	ull maybe = 0;
	// sll maybe = 0;
	// ull sum = 0;
	sll sum = 0;
	ull item;
	ull *dpcell;
	// qsort????"p"ullcomp???

	ull whites = 0;

	for (i = 0; i < n; i++) {
		if (c[i] == 'W') {
			a[i] += k;
		}
	}

	for (i = 0; i < n * 2; i++) {
		if (i < n) {
			a[i] %= (k * 2);
			b[i] %= (k * 2);	
		} else {
			a[i % n] = (a[i % n] + k) % (k * 2);
			b[i % n] = (b[i % n] + k) % (k * 2);
		}

		sll unity = +1;
		
		ull xlow = (a[i % n] + k + 1) % (k * 2);
		ull xhigh = a[i % n] + 1;
		ull ylow = (b[i % n] + k + 1) % (k * 2);
		ull yhigh = b[i % n] + 1;

		imos[xlow][ylow] += unity;
		imos[xhigh][yhigh] += unity;
		imos[xlow][yhigh] -= unity;
		imos[xhigh][ylow] -= unity;

		// printf("%llu %llu\n", a[i % n], b[i % n]);
		// for (ki = 0; ki < k * 2; ki++) {
		// 	for (l = 0; l < k * 2; l++) {
		// 		printf("%3lld ", imos[ki][l]);
		// 	}
		// 	puts("");
		// }
		// puts("");

		if (xlow > k) {
			imos[0][ylow] += unity;
			imos[0][yhigh] -= unity;
		}
		if (ylow > k) {
			imos[xlow][0] += unity;
			imos[xhigh][0] -= unity;
		}
		if (xlow > k && ylow > k) {
			imos[0][0] += unity;
		}

		// for (ki = 0; ki < k * 2; ki++) {
		// 	for (l = 0; l < k * 2; l++) {
		// 		printf("%3lld ", imos[ki][l]);
		// 	}
		// 	puts("");
		// }
		// puts("");
		// puts("");
	}

	result = whites;
	for (i = 0; i < k * 2; i++) {
		for (j = 0; j < k * 2; j++) {
			imoslow[j] += imos[i][j];
			// if (imos[i][j] != 0) printf("[%lld][%lld] %lld\n", i, j, imos[i][j]);
			// printf("imos[%lld][%lld]: %lld, imoslow[%lld]<- %lld\n", i, j, imos[i][j], j, imoslow[j]);
			// printf("%3lld ", imos[i][j]);
		}
		// puts("");

		sum = whites;
		for (j = 0; j < k * 2; j++) {
			sum += imoslow[j];
			if (sum > result) result = sum;
		}
	}

	printf("%llu\n", result);
	// printf("%.12lf\n", (double)result);
	// puts(s);

	return 0;

	success:
	// puts("YES");
	puts("Yes");
	// printf("%llu\n", result);
	// puts("Alice");
	return 0;

	fail:
	// puts("NO");
	puts("No");
	// puts("0");
	// puts("-1");
	// puts("-1 -1 -1");
	// puts("Borys");
	return 1;
}

int32_t main (void) {
	int32_t i, j;
	int32_t x, y;

	// scanf("%lf", &vda);
	// scanf("%lld%lld%lld%lld", &vsa, &vsb, &vsc, &vsd);
	// scanf("%llu%llu%llu%llu", &vua, &vub, &vuc, &vud);
	// scanf("%llu%llu", &h, &w);
	scanf("%llu", &n, &k);
	// scanf("%*llu");
	scanf("%llu", &k, &m, &n);
	// scanf("%llu%llu%llu%llu", &vua, &vub, &vuc, &vud, &vue);
	// scanf("%lld%lld", &vsa, &vsb, &vsc);
	// scanf("%s", s);
	// scanf("%s", t);
	// scanf("%llu", &vua);
	// for (i = 0; i < n; i++) {
	// 	scanf("%lld", &a[i]);
	// 	// a[i]--;
	// }
	// for (i = 0; i < n; i++) {
	// 	scanf("%llu", &arr[i].a);
	// 	scanf("%llu", &arr[i].b);
	// 	arr[i].a--;
	// 	arr[i].b--;
	// }
	// for (i = 0; i < n; i++) {
	// 	for (j = 0; j < n; j++) {
	// 		scanf("%llu", &a[i][j]);
	// 	}
	// }
	for (i = 0; i < n; i++) {
		scanf("%llu%llu %c", &a[i], &b[i], &c[i]);
	}

	// scanf("%llu", &q);
	// for (i = 0; i < q; i++) {
	// 	// scanf("%s%s", s, t);
	// 	// solve();
	// }

	// for (i = 0; i < m; i++) {
	// 	scanf("%llu%llu", &arr[i].a, &arr[i].b);
	// 	arr[i].a--;
	// 	arr[i].b--;
	// }
	// for (i = 0; i < n; i++) {
	// 	for (j = 0; j < m; j++) {
	// 		scanf("%llu", &a[i][j]);
	// 		a[i][j]--;
	// 	}
	// }

	solve();

	// for (i = 0; i < n; i++) {
	// 	// scanf("%llu%llu", &vua, &vub);
	// 	// scanf("%s%s", s, t);
	// 	// scanf("%f%f%f", &vda, &vdb, &vdc);
	// 	scanf("%s", s);
	// 	solve();
	// }

	// while (scanf("%llu%llu", &n, &k), n + k) {
	// 	for (i = 0; i < n; i++) {
	// 		scanf("%llu", &a[i]);
	// 	}
	// 	solve();
	// }

	return 0;
} ./Main.c: In function ‘printUquotient’:
./Main.c:370:9: warning: format ‘%llu’ expects argument of type ‘long long unsigned int’, but argument 2 has type ‘ull {aka long unsigned int}’ [-Wformat=]
  printf("%llu.", left / right);
         ^
./Main.c:374:10: warning: format ‘%d’ expects argument of type ‘int’, but argument 2 has type ‘ull {aka long unsigned int}’ [-Wformat=]
   printf("%1d", left / right);
          ^
./Main.c: In function ‘solve’:
./Main.c:573:9: warning: format ‘%llu’ expects argument of type ‘long long unsigned int’, but argument 2 has type ‘ull {aka long unsigned int}’ [-Wformat=]
  printf("%llu\n", result);
         ^
./Main.c: In function ‘main’:
./Main.c:604:8: warning: format ‘%llu’ expects argument of type ‘long long unsigned int *’, but argument 2 has type ‘ull * {aka long unsigned int *}’ [-Wformat=]
  scanf("%llu", &n, &k);
        ^
./Main.c:604:8: warning: too many arguments for format [-Wformat-extra-args]
./Main.c:606:8: warning: format ‘%llu’ expects argument of type ‘long ...