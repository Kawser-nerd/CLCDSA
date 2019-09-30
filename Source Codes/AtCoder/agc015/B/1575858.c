#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
 
#define BIG 2000000007
 
#define MOD 1000000007
typedef unsigned long long ull;
typedef   signed long long sll;
 
typedef struct {
	int a;
	int b;
} hw;
 
#define N_MAX 100000
#define M_MAX 100000
 
ull n, m, k;
ull h, w;
ull va, vb, vc, vd;
// ull a[N_MAX];
// sll a[N_MAX];
// ull b[N_MAX];
// ull dp[N_MAX][M_MAX + 1];
char s[N_MAX + 1];
// char t[N_MAX + 1];
// hw arr[N_MAX];
 
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

int comp(const void *left, const void *right){
	if ((*(int*)left) < (*(int*)right)) {
		return -1;
	} else if ((*(int*)left) > (*(int*)right)) {
		return +1;
	} else {
		return 0;
	}
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

ull solve(){
	int i, j;
	ull result;
	const size_t len = strlen(s);

	result = len * (len - 1);
	for (i = 0; i < len - 1; i++) {
		if (s[i] == 'U') {
			result += i;
		} else {
			result += (len - i - 1);
		}
	}

	printf("%llu\n", result);

	return 0;
}
 
int main(void){
	int i, j;
 
	// scanf("%llu", &n);
	// scanf("%llu%llu%llu%llu", &va, &vb, &vc, &vd);
	scanf("%s", s);

	solve();
 
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:137:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s", s);
  ^