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
ull va, vb, vc, vd, ve, vf;
ull a[N_MAX];
// sll a[N_MAX];
// ull wall[N_MAX][M_MAX];
ull b[N_MAX];
// sll b[N_MAX];
// char s[N_MAX + 1];
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
 
ull bitpow(ull a, ull x){
	ull result = 1;
	while (x) {
		if (x & 1) {
			result *= a;
			result %= MOD;
		}
		x /= 2;
		a = (a * a) % MOD;
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

int charcmp(const char *left, const char *right){
	if (*left < *right) {
		return -1;
	} else if (*left > *right) {
		return +1;
	} else {
		return 0;
	}
}

int intcomp(const int *left, const int *right){
	if (*left < *right) {
		return -1;
	} else if (*left > *right) {
		return +1;
	} else {
		return 0;
	}
}

int ullcomp(const ull *left, const ull *right){
	if (*left < *right) {
		return -1;
	} else if (*left > *right) {
		return +1;
	} else {
		return 0;
	}
}

int sllcomp(const sll *left, const sll *right){
	if (*left < *right) {
		return -1;
	} else if (*left > *right) {
		return +1;
	} else {
		return 0;
	}
}

int hwAcomp(const hw *left, const hw *right){
	return intcomp(&(left->a), &(right->a));
}
 
int hwBcomp(const hw *left, const hw *right){
	return intcomp(&(left->b), &(right->b));
}
 
int hwABcomp(const hw *left, const hw *right){
	int x = hwAcomp(left, right);
	if (x) return x;
	return hwBcomp(left, right);
}

int hwllAcomp(const hwll *left, const hwll *right){
	return sllcomp(&(left->a), &(right->a));
}
 
int hwllBcomp(const hwll *left, const hwll *right){
	return sllcomp(&(left->b), &(right->b));
}
 
int hwllABcomp(const hwll *left, const hwll *right){
	int x = hwllAcomp(left, right);
	if (x) return x;
	return hwllBcomp(left, right);
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

int strAcomp(const struct_a *left, const struct_a *right){
	return ullcomp(&(left->a), &(right->a));
}

int strBcomp(const struct_b *left, const struct_b *right){
	return ullcomp(&(left->cost), &(right->cost));
}

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


int fullfill(int x, int a, int b){
	int u = x / a;
	while (u >= 0) {
		if ((x - a * u) % b == 0) break;
		u--;
	}
	return u;
}

ull solve(){
	int i, j, ki;
	ull result = 0;

	qsort(a, n, sizeof(ull), ullcomp);

	for (i = 0; i < n; i++) {
		ull mustbe = ((n % 2) ? ((i + 1) / 2) * 2 : (i / 2) * 2 + 1);
		if (a[i] != mustbe) {
			puts("0");
			return 1;
		}
	}

	printf("%llu\n", bitpow(2, n / 2));

	return 0;
}
 
int main(void){
	int i, j;
	int x, y;

	scanf("%llu", &n, &m);
	// scanf("%llu%llu", &h, &w);
	// scanf("%s", s);
	// scanf("%s", t);
	// scanf("%llu%llu%llu", &k, &va, &vb);
	for (i = 0; i < n; i++) {
		scanf("%llu", &a[i], &b[i]);
	}

	solve();

	// for (i = 0; i < m; i++) {
	// 	scanf("%llu%llu", &va, &vb);
	// 	solve();
	// }

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:329:8: warning: too many arguments for format [-Wformat-extra-args]
  scanf("%llu", &n, &m);
        ^
./Main.c:335:9: warning: too many arguments for format [-Wformat-extra-args]
   scanf("%llu", &a[i], &b[i]);
         ^
./Main.c:329:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%llu", &n, &m);
  ^
./Main.c:335:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%llu", &a[i], &b[i]);
   ^