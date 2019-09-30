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

#define MOD 1000000007
typedef uint64_t ull;
typedef  int64_t sll;

#define N_MAX 100000
#define M_MAX 30

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
ull vua, vub, vuc, vud, vue, vuf;
sll vsa, vsb, vsc, vsd, vse, vsf;
long double vra, vrb, vrc;
size_t slen;
size_t tlen;
ull a[N_MAX];
// sll a[N_MAX];
// ull a[N_MAX][N_MAX];
// ull wall[M_MAX][N_MAX];
// ull b[N_MAX];
// sll b[N_MAX];
// ull b[N_MAX][N_MAX];
// sll b[N_MAX][N_MAX];
// ull c[N_MAX];
char s[N_MAX + 1];
// char t[N_MAX + 1];
// char s[N_MAX][M_MAX + 1];

ull dp[N_MAX];
// sll dp[N_MAX];
// bool dp[N_MAX];
ull dq[N_MAX];
// ull dp[N_MAX + 1][M_MAX + 1];
// ull dq[M_MAX][N_MAX];
// bool dq[N_MAX];
// hwll dp[N_MAX + 1][N_MAX + 1];
// struct_a dp[N_MAX + 1][N_MAX + 1];

// hw arr[N_MAX];
// hwll arr[N_MAX * 2];
// hw brr[M_MAX];
// linell arr[N_MAX];

// ull bitdp[1 << N_MAX];

// ull digitdp[10001][   2][  100];
//            pos  less  carry


// struct_a arr[N_MAX * 2];
// struct_b brr[N_MAX * 2];

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

// int32_t nextroute (int32_t arr[]) {
// 	int32_t i = n - 1;
// 	int32_t j, x;
// 	while (arr[i - 1] > arr[i]) i--;

// 	x = n;
// 	for (j = i; j < n; j++) {
// 		if (arr[j] < arr[i - 1]) continue;
// 		if (x == n || arr[x] > arr[j]) x = j;
// 	}
// 	arr[i - 1] ^= arr[x];
// 	arr[x] ^= arr[i - 1];
// 	arr[i - 1] ^= arr[x];

// 	qsort(&arr[i], n - i, sizeof(int32_t), comp);
// 	return 0;
// }

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

int32_t pcharcomp (const char *left, const char *right) {
	return charcomp(*left, *right);
}

int32_t pcharrevcomp (const char *left, const char *right) {
	return charcomp(*right, *left);
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

int32_t pintcomp (const int32_t *left, const int32_t *right) {
	return intcomp(*left, *right);
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

int32_t pullcomp (const ull *left, const ull *right) {
	return ullcomp(*left, *right);
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

int32_t psllcomp (const sll *left, const sll *right) {
	return sllcomp(*left, *right);
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

int32_t phwllABcomp (const hwll *left, const hwll *right) {
	int32_t x = phwllAcomp(left, right);
	if (x) return x;
	return phwllBcomp(left, right);
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

void printquotient (ull left, ull right) {
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


bool isonedge (hwll x) {
	return (x.a == 0) || (x.a == h) || (x.b == 0) || (x.b == w);
}

ull converttoint (hwll x) {
	if (x.a == 0) {
		return w - x.b; // w ~ 0
	} else if (x.b == 0) {
		return w + x.a; // w ~ h+w
	} else if (x.a == h) {
		return (h + w) + x.b; // h+w ~ h+2w
	} else {
		return (h + w) * 2 - x.a; // (2h+2w) ~ (h+2w)
	}
}

ull solve () {
	sll i, j, ki, l;
	ull result = 0;
	// sll result = 0;
	ull sum = 0;
	// sll sum = 0;
	ull item;
	// qsort????"p"ullcomp???

	// if (k % 2 == 0) {
	// 	for (i = 0; i < n; i++) {
	// 		printf("%llu%c", ((i == 0) ? (k / 2 - 1) : (k / 2)), ((i == n - 1) ? '\n' : ' '));
	// 	}
	// } else {
	// 	//
	// }

	// ull p2, p3, p5;
	// p2 = p3 = p5 = 0;
	// while (n % 2) {
	// 	n /= 2;
	// 	p2++;
	// }
	// while (n % 3) {
	// 	n /= 3;
	// 	p3++;
	// }
	// while (n % 5) {
	// 	n /= 5;
	// 	p5++;
	// }
	// if (n > 1) goto fail;

	slen = strlen(s);

	for (i = 0; i < slen; i++) {
		dp[i] = ((s[i] == 'o') ? 0 : 1);
	}

	if (slen == 3) {
		if (dp[0] == dp[1] && dp[1] == dp[2]) {
			dq[0] = dq[1] = 0;
			dq[2] = dp[0];
		} else {
			goto fail;
		}
	} else {
		for (i = 0; i < (1 << 2); i++) {
			for (j = 0; j < n; j++) {
				if (j < 2) {
					dq[j] = (i >> j) & 1;
					continue;
				}
				dq[j] = (dq[j - 2] ^ dq[j - 1]) ^ dp[j - 1];
			}

			if ((dq[n - 2] ^ dq[n - 1] ^ dq[0]) ^ dp[n - 1]) continue;
			if ((dq[n - 1] ^ dq[0] ^ dq[1]) ^ dp[0]) continue;
			break;
		}
		if (i == (1 << 2)) goto fail;
	}

	for (i = 0; i < n; i++) {
		putchar(dq[i] ? 'W' : 'S');
	}
	puts("");

	// printf("%llu\n", result);
	// puts(s);

	return 0;

	success:
	puts("YES");
	// puts("Yes");
	// printf("%llu\n", result);
	return 0;

	fail:
	// put("NO");
	// puts("No");
	// puts("0");
	puts("-1");
	return 1;
}

int32_t main (void) {
	int32_t i, j;
	int32_t x, y;

	// scanf("%llu%llu", &h, &w);
	scanf("%llu", &n, &k);
	// scanf("%llu%llu", &k, &n);
	// scanf("%llu%llu", &vua, &vub, &vuc, &vud);
	scanf("%s", s);
	// scanf("%s", t);
	// scanf("%lld%lld", &vsa, &vsb);
	// for (i = 0; i < n; i++) {
	// 	scanf("%llu", &a[i]);
	// }

	// for (i = 0; i < h; i++) {
	// 	scanf("%llu", &a[i]);
	// }
	// for (i = 0; i < w; i++) {
	// 	scanf("%llu", &b[i]);
	// }
	// for (i = 0; i < n; i++) {
	// 	scanf("%llu%llu", &b[i], &a[i]);
	// }
	// for (i = 0; i < h; i++) {
	// 	for (j = 0; j < w; j++) {
	// 		scanf("%llu", &a[i][j]);
	// 	}
	// }

	solve();

	// for (i = 0; i < n; i++) {
	// 	// scanf("%llu%llu", &vua, &vub);
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
} ./Main.c: In function ‘printquotient’:
./Main.c:335:9: warning: format ‘%llu’ expects argument of type ‘long long unsigned int’, but argument 2 has type ‘ull {aka long unsigned int}’ [-Wformat=]
  printf("%llu.", left / right);
         ^
./Main.c:339:10: warning: format ‘%d’ expects argument of type ‘int’, but argument 2 has type ‘ull {aka long unsigned int}’ [-Wformat=]
   printf("%1d", left / right);
          ^
./Main.c: In function ‘main’:
./Main.c:456:8: warning: format ‘%llu’ expects argument of type ‘long long unsigned int *’, but argument 2 has type ‘ull * {aka long unsigned int *}’ [-Wformat=]
  scanf("%llu", &n, &k);
        ^
./Main.c:456:8: warning: too many arguments for format [-Wformat-extra-args]
./Main.c:456:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%llu", &n, &k);
  ^
./Main.c:459:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s", s);
  ^