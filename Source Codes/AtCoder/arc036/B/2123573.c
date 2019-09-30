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
#include <time.h>

#define BIG 2000000007
#define VERYBIG 200000000000007LL

#define MOD 1000000007
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

ull a[N_MAX];
// ull a[M_MAX];
// sll a[N_MAX];
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
// hwll arr[N_MAX];
hwll arr[M_MAX];
// hwll brr[M_MAX];

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

ull solve () {
	sll i, j, ki;
	// ull result = 0;
	sll result = 0;
	// double result = 0;
	ull maybe = 0;
	// sll maybe = 0;
	ull sum = 0;
	// sll sum = 0;
	ull item;
	ull *dpcell;

	// for (i = 0; i < n; i++) {
	// 	a[i] = arr[i].a;
	// 	b[i] = arr[i].b;
	// }
	// qsort(a, n, sizeof(ull), pullcomp);
	// qsort(b, n, sizeof(ull), pullcomp);

	// ull xl = a[(n - 1) / 2], xr = a[n / 2];
	// ull yl = b[(n - 1) / 2], yr = b[n / 2];

	// ull maxloss = 0;
	// ull goodx = arr[0].a, goody = arr[0].b;
	// for (i = 0; i < n; i++) {
	// 	result += ullabs(arr[i].a, xl) + ullabs(arr[i].b, yl);

	// 	ull mayx, mayy;
	// 	if (ullabs(arr[i].a, xl) > ullabs(arr[i].a, xr)) {
	// 		mayx = xl;
	// 	} else {
	// 		mayx = xr;
	// 	}
	// 	if (ullabs(arr[i].b, yl) > ullabs(arr[i].b, yr)) {
	// 		mayy = yl;
	// 	} else {
	// 		mayy = yr;
	// 	}

	// 	maybe = ullabs(arr[i].a, mayx) + ullabs(arr[i].b, mayy);
	// 	if (maybe > maxloss) {
	// 		maxloss = maybe;

	// 		goodx = mayx;
	// 		goody = mayy;
	// 		// printf("%llu (%llu,%llu)\n", maxloss, goodx, goody);
	// 	}
	// }
	// // printf("%llu*2-%llu=\n", result, maybe);
	// result = result * 2 - maxloss;

	// printf("%llu\n", result);
	// printf("%llu %llu\n", goodx + 1, goody + 1);

	// for (i = 0; i < n; i++) {
	// 	dp[i] = -1;
	// }

	// for (i = 0; i < m; i++) {
	// 	children[arr[i].a].insert(arr[i].b);
	// 	children[arr[i].b].insert(arr[i].a);
	// }

	// typedef pair<sll, sll> P;

	// queue<P> que;

	// for (i = q - 1; i >= 0; i--) {
	// 	printf("%llu! (%llu)\n", i, c[i]);

	// 	que.push(P(b[i], a[i]));
	// 	while (!que.empty()) {
	// 		P p = que.front();
	// 		que.pop();

	// 		sll cost = p.first;
	// 		sll v = p.second;

	// 		if (dp[v] > cost) continue;

	// 		if (dp[v] < 0) {
	// 			color[v] = c[i];
	// 			dp[v] = 0;
	// 			leaf[v].insert(v);
	// 		}

	// 		set<sll> allc;
	// 		for (sll currl : leaf[v]) {
	// 			for (sll nextv : children[currl]) {
	// 				if (dp[nextv] <= cost - 1) {
	// 					allc.insert(nextv);
	// 				}
	// 			}
	// 		}
	// 		leaf[v] = allc;
	// 		for (sll x : allc) {
	// 			que.push(P(cost - 1, x));
	// 		}

	// 		printf("dp[%llu] (%llu->%llu)\n", v, dp[v], dp[v] + 1);
	// 		dp[v]++;
	// 	}
	// }

	// for (i = 0; i < n; i++) {
	// 	printf("%llu\n", color[i]);
	// }

	result = 1;
	i = 0;
	while (i < n - 1) {
		j = i;
		while (j < n - 1 && a[j] < a[j + 1]) j++;
		while (j < n - 1 && a[j] > a[j + 1]) j++;

		result = umax(result, j - i + 1);

		i = j;
	}

	printf("%llu\n", result);
	// printf("%.12lf\n", (double)result);
	// puts(s);

	return 0;

	success:
	// puts("YES");
	// puts("Yes");
	// printf("%llu\n", result);
	// puts("0");
	puts("Possible");
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

	// scanf("%lf%lf", &vda, &vdb);
	// scanf("%lld%lld%lld%lld", &vsa, &vsb, &vsc, &vsd);
	// scanf("%llu%llu", &vua, &vub, &vuc, &vud);
	// scanf("%llu%llu", &h, &w);
	// scanf("%*llu%*llu");
	scanf("%llu", &n, &m);
	// scanf("%llu", &k, &m, &n);
	// scanf("%llu%llu%llu%llu", &vua, &vub, &vuc, &vud, &vue, &vuf);
	// scanf("%lld%lld", &vsa, &vsb, &vsc);
	// scanf("%s", s);
	// scanf("%s", t);
	// scanf("%llu", &m);
	// scanf("%llu", &q);
	for (i = 0; i < n; i++) {
		scanf("%llu", &a[i]);
		// a[i]--;
	}
	// for (i = 0; i < m; i++) {
	// 	scanf("%llu", &b[i]);
	// }
	// for (i = 0; i < h; i++) {
	// 	scanf("%llu", &a[i]);
	// }
	// for (i = 0; i < h; i++) {
	// 	for (j = 0; j < w; j++) {
	// 		scanf("%llu", &a[i][j]);
	// 	}
	// }

	// for (i = 0; i < w; i++) {
	// 	scanf("%llu", &b[i]);
	// }	
	// for (i = 0; i < m; i++) {
	// 	scanf("%llu", &b[i]);
	// }
	// for (i = 0; i < h; i++) {
	// 	scanf("%s", s[i]);
	// }
	// scanf("%s", t);
	// for (i = 0; i < m; i++) {
	// 	// scanf("%llu", &a[i]);
	// 	// scanf("%llu", &b[i]);
	// 	scanf("%llu", &arr[i].a);
	// 	scanf("%llu", &arr[i].b);
	// 	// scanf("%llu", &c[i]);
	// 	arr[i].a--;
	// 	arr[i].b--;
	// 	// a[i]--;
	// 	// b[i]--;
	// }
	// for (i = 0; i < k; i++) {
	// 	scanf("%llu", &c[i]);
	// 	c[i]--;
	// }
	// for (i = 0; i < m; i++) {
	// 	scanf("%llu%llu", &arr[i].a, &arr[i].b);
	// 	arr[i].a--;
	// 	arr[i].b--;
	// }
	// for (i = 0; i < k; i++) {
	// 	scanf("%llu%llu", &brr[i].a, &brr[i].b);
	// 	brr[i].a--;
	// 	brr[i].b--;
	// }
	// for (i = 0; i < m; i++) {
	// 	for (j = 0; j < m; j++) {
	// 		scanf("%llu", &a[i][j]);
	// 	}
	// }
	// for (i = 0; i < n; i++) {
	// 	scanf("%llu%llu%llu", &a[i], &b[i], &c[i]);
	// }

	// scanf("%llu", &q);
	// scanf("%llu", &k);
	// k--;
	// for (i = 0; i < q; i++) {
	// 	scanf("%llu%llu%llu", &a[i], &b[i], &c[i]);
	// 	a[i]--;
	// 	b[i]--;
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

	// for (i = 0; i < m; i++) {
	// 	scanf("%llu%llu%llu", &vua, &vub, &vuc);
	// 	// scanf("%s%s", s, t);
	// 	// scanf("%f%f%f", &vda, &vdb, &vdc);
	// 	// scanf("%s", s);
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
./Main.c:199:9: warning: format ‘%llu’ expects argument of type ‘long long unsigned int’, but argument 2 has type ‘ull {aka long unsigned int}’ [-Wformat=]
  printf("%llu.", left / right);
         ^
./Main.c:203:10: warning: format ‘%d’ expects argument of type ‘int’, but argument 2 has type ‘ull {aka long unsigned int}’ [-Wformat=]
   printf("%1d", left / right);
          ^
./Main.c: In function ‘solve’:
./Main.c:470:9: warning: format ‘%llu’ expects argument of type ‘long long unsigned int’, but argument 2 has type ‘sll {aka long int}’ [-Wformat=]
  printf("%llu\n", result);
         ^
./Main.c: In function ‘main’:
./Main.c:503:8: warning: format ‘%llu’ expects argument of type ‘long long unsigned int *’, but argument 2 has type ‘ull * {aka long unsigned int *}’ [-Wformat=]
  scanf("%llu", &n, &m);
        ^
./Main.c:503:8: warning: too many arguments for format [-Wformat-extra-args]
./Main.c:512:9: warning: format ‘%llu’ expects argument of type ‘long long unsi...