#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
// ull b[N_MAX];
// ull dp[N_MAX][M_MAX + 1];
// char s[N_MAX + 1];
// char t[N_MAX + 1];
// hw arr[N_MAX];
// hw brr[N_MAX];
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
 
int min(ull x, ull y){
	return (x < y) ? x : y;
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

int nibutan_target(ull target){
	ull maxdist = (target * (target + 1) / 2); // ??target???????????[-maxdist, maxdist]
	return (n <= maxdist);
}

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

int findarr(hw arr[], int length, int h, int w){
	int minok = length - 1;
	int minng = -1;

	while (minng + 1 < minok) {
		int med = (minok + minng) / 2;
		if (arr[med].a <= h) {
			minok = med;
		} else {
			minng = med;
		}
	}
	if (arr[minok].a != h) return 0;

	int maxok = minok;
	int maxng = length;

	while (maxok + 1 < maxng) {
		int med = (maxok + maxng) / 2;
		if (arr[med].a <= h) {
			maxok = med;
		} else {
			maxng = med;
		}
	}

	minok = minok;
	minng = maxok + 1;
	while (minok + 1 < minng) {
		int med = (maxok + maxng) / 2;
		if (arr[med].b < w) {
			minok = med;
		} else if (arr[med].b > w) {
			minng = med;
		} else {
			return 1;
		}
	}
	if (arr[minok].a != w) return 0;

	return 1;
}

ull solve(){
	int i, j;
	// int pos, less, carry;
	// const int posmax = strlen(s);
	// int stackmax = -1;
	ull result = 0;
	int lastindex = 0;

	for (i = 0; i < n; i++) {
		ull time;
		if (i == n - 1 || a[i + 1] - a[i] > k) {
			time = k;
		} else {
			time = a[i + 1] - a[i];
		}
		result += time;
	}


	printf("%llu\n", result);

	return 0;
}
 
int main(void){
	int i, j;
	int x;

	scanf("%llu%llu", &n, &k);

	for (i = 0; i < n; i++) {
		scanf("%llu", &a[i]);
	}

	solve();

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:240:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%llu%llu", &n, &k);
  ^
./Main.c:243:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%llu", &a[i]);
   ^