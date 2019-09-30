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
#define M_MAX 100000
 
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
sll va, vb, vc, vd, ve, vf;
ull a[N_MAX];
// sll a[N_MAX];
ull b[N_MAX];
// sll b[M_MAX];
// char s[N_MAX + 1];
// char t[N_MAX + 1];
// char s[N_MAX][M_MAX + 1];

// ull dp[N_MAX];
// ull dp[N_MAX + 1][N_MAX + 1];
// ull dp[N_MAX][M_MAX + 1];

// hw arr[N_MAX];
// hwll arr[N_MAX];
// hw brr[M_MAX];

struct_a arr[N_MAX * 2];
struct_b brr[N_MAX * 2];

// ull digitdp[102][   2][    2];
//          pos  less  carry
 
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
 
ull min(ull x, ull y){
	return (x < y) ? x : y;
}

ull max(ull x, ull y){
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
 
int intcomp(const void *left, const void *right){
	if ((*(int*)left) < (*(int*)right)) {
		return -1;
	} else if ((*(int*)left) > (*(int*)right)) {
		return +1;
	} else {
		return 0;
	}
}

int ullcomp(const void *left, const void *right){
	if ((*(ull*)left) < (*(ull*)right)) {
		return -1;
	} else if ((*(ull*)left) > (*(ull*)right)) {
		return +1;
	} else {
		return 0;
	}
}

int sllcomp(const void *left, const void *right){
	if ((*(sll*)left) < (*(sll*)right)) {
		return -1;
	} else if ((*(sll*)left) > (*(sll*)right)) {
		return +1;
	} else {
		return 0;
	}
}

int hwAcomp(const void *left, const void *right){
	return intcomp(&(((hw*)left)->a), &(((hw*)right)->a));
}
 
int hwBcomp(const void *left, const void *right){
	return intcomp(&(((hw*)left)->b), &(((hw*)right)->b));
}
 
int hwABcomp(const void *left, const void *right){
	int x = hwAcomp(left, right);
	if (x) return x;
	return hwBcomp(left, right);
}

int hwllAcomp(const void *left, const void *right){
	return sllcomp(&(((hw*)left)->a), &(((hw*)right)->a));
}
 
int hwllBcomp(const void *left, const void *right){
	return sllcomp(&(((hw*)left)->b), &(((hw*)right)->b));
}
 
int hwllABcomp(const void *left, const void *right){
	int x = hwllAcomp(left, right);
	if (x) return x;
	return hwllBcomp(left, right);
}

int strAcomp(const struct_a *left, const struct_a *right){
	return ullcomp(&(left->a), &(right->a));
}

int strBcomp(const struct_b *left, const struct_b *right){
	return ullcomp(&(left->cost), &(right->cost));
}

int bitlet(char c){
	return (1 << (c - 'a'));
}


ull seg[262144];
ull baseIndex;

int initSeg(ull a[], int num) {
	int i;

	baseIndex = 1;
	while (baseIndex < num) baseIndex *= 2;

	for (i = 0; i < baseIndex; i++) {
		seg[baseIndex + i] = (i < num ? a[i] : 0);
	}
	for (i = baseIndex - 1; i >= 1; i--) {
		seg[i] = seg[i * 2] + seg[i * 2 + 1];
	}

}

ull plainAnswerSeg(int num) {
	ull lookIndex = baseIndex;
	ull result = 0;

	while (num) {
		if (num % 2 == 1) {
			result += seg[lookIndex + num - 1];
		}

		lookIndex /= 2;
		num /= 2;
	}

	return result;
}


int parent[N_MAX];
int rank[N_MAX];

void uf_init(int n){
	int i;
	for (i = 0; i < n; i++) {
		parent[i] = i;
		rank[i] = 0;
	}
}

int uf_find(int x){
	if (parent[x] == x) {
		return x;
	} else {
		return parent[x] = uf_find(parent[x]);
	}
}

int uf_unite(int x, int y){
	x = uf_find(x);
	y = uf_find(y);
	if (x == y) return 1;

	if (rank[x] < rank[y]) {
		parent[x] = y;
	} else {
		parent[y] = x;
		if (rank[x] == rank[y]) rank[x]++;
	}
}

bool uf_same(int x, int y){
	return uf_find(x) == uf_find(y);
}


ull gapAnswerSeg(int start, int end){
	if (start > end) return gapAnswerSeg(end, start);
	return plainAnswerSeg(end) - plainAnswerSeg(start - 1);
}

ull ulldiff(ull a, ull b){
	if (a >= b) {
		return a - b;
	} else {
		return b - a;
	}
}

ull ullkaijo(ull a){
	ull i;
	ull result = 1;
	for (i = 1; i <= a; i++) {
		result *= i;
		result %= MOD;
	}
	return result;
}

ull solve(){
	int i, j, ki;

	for (i = 0; i < n; i++) {
		arr[i].a = a[i];
		arr[i].i = i;
	}
	qsort(arr, n, sizeof(struct_a), strAcomp);
	for (i = 0; i < n - 1; i++) {
		brr[i].cost = arr[i + 1].a - arr[i].a;
		brr[i].left = arr[i].i;
		brr[i].right = arr[i + 1].i;
	}

	for (i = 0; i < n; i++) {
		arr[i].a = b[i];
		arr[i].i = i;
	}
	qsort(arr, n, sizeof(struct_a), strAcomp);
	for (i = 0; i < n - 1; i++) {
		brr[i + (n - 1)].cost = arr[i + 1].a - arr[i].a;
		brr[i + (n - 1)].left = arr[i].i;
		brr[i + (n - 1)].right = arr[i + 1].i;
	}

	qsort(brr, (n - 1) * 2, sizeof(struct_b), strBcomp);

	uf_init(n);


	int path = 1;
	i = 0;
	ull result = 0;
	while (path < n) {
		struct_b brri = brr[i];
		if (!uf_same(brri.left, brri.right)) {
			uf_unite(brri.left, brri.right);
			path++;
			result += brri.cost;
		}
		i++;
	}

	printf("%llu\n", result);

	return 0;
}
 
int main(void){
	int i, j;
	int x, y;

	scanf("%llu", &n, &m);
	for (i = 0; i < n; i++) {
		scanf("%llu%llu", &a[i], &b[i]);
	}

	solve();

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:387:8: warning: too many arguments for format [-Wformat-extra-args]
  scanf("%llu", &n, &m);
        ^
./Main.c:387:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%llu", &n, &m);
  ^
./Main.c:389:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%llu%llu", &a[i], &b[i]);
   ^