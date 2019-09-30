/*
cat <<EOF >mistaken-paste
*/

#pragma GCC diagnostic ignored "-Wincompatible-pointer-types"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#define BIG 2000000007

#define MOD 1000000007
typedef unsigned long long ull;
typedef   signed long long sll;

#define N_MAX 200000
#define M_MAX 200

typedef struct {
	int a;
	int b;
} hw;

typedef struct {
	sll a;
	sll b;
} hwll;


typedef struct {
	ull a;
	int i;
} struct_a;

typedef struct {
	ull cost;
	int left;
	int right;
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
ull vua, vub, vuc, vud, vue, vuf;
sll vsa, vsb, vsc, vsd, vse, vsf;
// ull a[N_MAX];
// sll a[N_MAX];
// ull wall[N_MAX][M_MAX];
// ull b[N_MAX];
// sll b[N_MAX];
char s[N_MAX + 1];
// char t[N_MAX + 1];
// char s[N_MAX][M_MAX + 1];

// ull dp[N_MAX];
// sll dp[N_MAX];
// ull dp[N_MAX + 1][N_MAX + 1];
// ull dp[N_MAX][M_MAX + 1];

// hw arr[N_MAX];
// hwll arr[N_MAX];
// hw brr[M_MAX];

// ull digitdp[102][   2][    2];
//          pos  less  carry


// struct_a arr[N_MAX * 2];
// struct_b brr[N_MAX * 2];

void swap_adj(ull *a, ull *b){
	ull tmp = *b;
	*b = *a;
	*a = tmp;
	return;
}

ull divide(ull a, ull b){
	ull x = MOD - 2;
	ull ans = 1;
	while (x) {
		if (x & 1) ans = (ans * b) % MOD;
		b = (b * b) % MOD;
		x /= 2;
	}
	return (a * ans) % MOD;
}

int digits(ull x){
	int i = 1;
	while (x >= 10) {
		x /= 10;
		i++;
	}
	return i;
}

ull umin(ull x, ull y){
	return (x < y) ? x : y;
}

ull umax(ull x, ull y){
	return (x > y) ? x : y;
}

sll smin(sll x, sll y){
	return (x < y) ? x : y;
}

sll smax(sll x, sll y){
	return (x > y) ? x : y;
}

ull gcd(ull x, ull y){
	if (x < y) {
		return gcd(y, x);
	} else if (y == 0) {
		return x;
	} else {
		return gcd(y, x % y);
	}
}

ull bitpow(ull a, ull x, ull modulo){
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

// int nextroute(int arr[]){
// 	int i = n - 1;
// 	int j, x;
// 	while (arr[i - 1] > arr[i]) i--;

// 	x = n;
// 	for (j = i; j < n; j++) {
// 		if (arr[j] < arr[i - 1]) continue;
// 		if (x == n || arr[x] > arr[j]) x = j;
// 	}
// 	arr[i - 1] ^= arr[x];
// 	arr[x] ^= arr[i - 1];
// 	arr[i - 1] ^= arr[x];

// 	qsort(&arr[i], n - i, sizeof(int), comp);
// 	return 0;
// }

int targetdig(ull x, int index /* 1-indexed */){
	// static...?
	int posmax = digits(x);
	if (posmax < index) return -1;
	while (posmax > index) {
		posmax--;
		x /= 10;
	}
	return x % 10;
}

int charcomp(const char left, const char right){
	if (left < right) {
		return -1;
	} else if (left > right) {
		return +1;
	} else {
		return 0;
	}
}

int pcharcomp(const char *left, const char *right){
	return charcomp(*left, *right);
}

int intcomp(const int left, const int right){
	if (left < right) {
		return -1;
	} else if (left > right) {
		return +1;
	} else {
		return 0;
	}
}

int pintcomp(const int *left, const int *right){
	return intcomp(*left, *right);
}

int ullcomp(const ull left, const ull right){
	if (left < right) {
		return -1;
	} else if (left > right) {
		return +1;
	} else {
		return 0;
	}
}

int pullcomp(const ull *left, const ull *right){
	return ullcomp(*left, *right);
}

int sllcomp(const sll left, const sll right){
	if (left < right) {
		return -1;
	} else if (left > right) {
		return +1;
	} else {
		return 0;
	}
}

int psllcomp(const sll *left, const sll *right){
	return sllcomp(*left, *right);
}

int phwAcomp(const hw *left, const hw *right){
	return intcomp(left->a, right->a);
}

int phwBcomp(const hw *left, const hw *right){
	return intcomp(left->b, right->b);
}

int phwABcomp(const hw *left, const hw *right){
	int x = phwAcomp(left, right);
	if (x) return x;
	return phwBcomp(left, right);
}

int phwllAcomp(const hwll *left, const hwll *right){
	return sllcomp(left->a, right->a);
}

int phwllBcomp(const hwll *left, const hwll *right){
	return sllcomp(left->b, right->b);
}

int phwllABcomp(const hwll *left, const hwll *right){
	int x = phwllAcomp(left, right);
	if (x) return x;
	return phwllBcomp(left, right);
}

// int hw_lowerbound(hw arr[], int length, const hw x){
// 	int ok = 0;
// 	int ng = length;
// 	while (ok + 1 < ng) {
// 		int med = (ok + ng) / 2;
// 		if (hwABcomp(&arr[med], &x) >= 0) {
// 			ok = med;
// 		} else {
// 			ng = med;
// 		}
// 	}
// 	return ok;
// }

// int hw_upperbound(hw arr[], int length, const hw x){
// 	int ok = 0;
// 	int ng = length;
// 	while (ok + 1 < ng) {
// 		int med = (ok + ng) / 2;
// 		if (hwABcomp(&arr[med], &x) > 0) {
// 			ok = med;
// 		} else {
// 			ng = med;
// 		}
// 	}
// 	return ok;
// }

int bitlet(char c){
	return (1 << (c - 'a'));
}

ull ulldiff(ull a, ull b){
	if (a >= b) {
		return a - b;
	} else {
		return b - a;
	}
}


ull solve(){
	int i, j, ki;
	ull result = 0;

	i = 0;
	n = strlen(s);
	while (i < n) {
		switch (s[i]) {
		case 'd':
			if (strncmp(s + i, "dream", 5) == 0) {
				i += 5;
				if (strncmp(s + i, "er", 2) && !(i + 2 < n && s[i + 2] != 'a')) i += 2;
			} else {
				goto fail;
			}
			break;
		case 'e':
			if (strncmp(s + i, "erase", 5) == 0) {
				i += 5;
				if (s[i] == 'r') i++;
			} else {
				goto fail;
			}
			break;
		default:
			goto fail;
		}
		// printf("%d...\n", i);
	}

	puts("YES");
	return 0;

	fail:
	puts("NO");
	return 1;

	// // dp[i][j] := i?????j????????????????????min/max
	// for (i = 0; i < n; i++) {
	// 	for (j = 0; j <= i + 1; j++) {
	// 		if (i == 0) {
	// 			hwll agree = {arr[0].a, 0};
	// 			hwll disagree = {0, arr[0].b};
	// 			dp[0][0].minzed = dp[0][0].maxzed = disagree;
	// 			dp[0][1].minzed = dp[0][1].maxzed = agree;

	// 			continue;
	// 		}

	// 		hwll agree, disagree;
	// 		if (j == 0) {
	// 			agree.a = 0;
	// 			agree.b = BIG;
	// 		} else {
	// 			agree = dp[i - 1][j - 1].minzed;
	// 			agree.a += arr[i].a;
	// 		}
	// 		disagree = dp[i - 1][j].maxzed;
	// 		disagree.b += arr[i].b;

	// 		switch (ullcomp(agree.a * (disagree.a + disagree.b), disagree.a * (agree.a + agree.b))) {
	// 		case -1:
	// 			dp[i][j].minzed = dp[i][j].maxzed = disagree;
	// 			break;
	// 		case +1:
	// 			dp[i][j].minzed = dp[i][j].maxzed = agree;
	// 			break;
	// 		case 0:
	// 			switch (ullcomp(agree.a, disagree.a)) {
	// 			case -1:
	// 				dp[i][j].maxzed = disagree;
	// 				dp[i][j].minzed = agree;
	// 				break;
	// 			default:
	// 				dp[i][j].maxzed = agree;
	// 				dp[i][j].minzed = disagree;
	// 			}
	// 			break;
	// 		}
	// 	}
	// }

	// for (i = 0; i <= n; i++) {
	// 	printf("%d: %llu::%llu / %llu::%llu\n", i,
	// 		dp[n - 1][i].minzed.a,
	// 		dp[n - 1][i].minzed.b,
	// 		dp[n - 1][i].maxzed.a,
	// 		dp[n - 1][i].maxzed.b);
	// }

	// result = 0;
	// while (true) {
	// 	hwll bestvotes = dp[n - 1][result].maxzed;
	// 	if (bestvotes.a * 100 >= k * (bestvotes.a + bestvotes.b)) break;
	// 	result++;
	// }

	// printf("%llu\n", result);
	// puts(s);

	return 0;
}

int main(void){
	int i, j;
	int x, y;

	scanf("%llu%llu", &n, &m);
	if (m == 1) puts("2");
	else puts("1");
	return 0;
	// scanf("%llu%llu", &h, &w);
	// scanf("%llu", &k);
	scanf("%s", s);
	// scanf("%s", t);
	// for (i = 0; i < n; i++) {
	// 	scanf("%llu%llu", &(arr[i].a), &(arr[i].b));
	// }

	solve();

	// for (i = 0; i < n; i++) {
	// 	// scanf("%llu%llu", &vua, &vub);
	// 	scanf("%s", s);
	// 	solve();
	// }

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:413:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%llu%llu", &n, &m);
  ^
./Main.c:419:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s", s);
  ^