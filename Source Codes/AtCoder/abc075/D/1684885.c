#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
 
#define BIG 2000000007
 
#define MOD 1000000007
typedef unsigned long long ull;
typedef   signed long long sll;

#define N_MAX 100
#define M_MAX 100
 
typedef struct {
	int a;
	int b;
} hw;

typedef struct {
	sll a;
	sll b;
} hwll;
 
 
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
// ull a[N_MAX];
// sll a[N_MAX];
// ull b[M_MAX];
// ull dp[N_MAX][M_MAX + 1];
// char s[N_MAX + 1];
// char t[N_MAX + 1];
// char s[N_MAX][M_MAX + 1];
// hw arr[N_MAX];
hwll arr[N_MAX];
// hw brr[M_MAX];
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

ull solve(){
	int i, j, ki;

	int stack[N_MAX] = {0};
	int stackend = 0;
	int stacksize = 0;
	ull result = 0;

	qsort(arr, n, sizeof(hwll), hwllABcomp);

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {

			if (i == j || arr[i].b > arr[j].b) continue;
			if (k == 2) {
				ull maybe = (arr[j].b - arr[i].b) * (arr[i].a > arr[j].a ? arr[i].a - arr[j].a : arr[j].a - arr[i].a);
				if (result == 0 || maybe < result) {
					result = maybe;
				}
				continue;
			}
			stackend = 0;
			stacksize = 0;

			for (ki = 0; ki < n; ki++) {
				if (i == ki || j == ki) continue;
				if (arr[ki].b < arr[i].b || arr[ki].b > arr[j].b) continue;

				stack[stackend] = ki;
				stackend = (stackend + 1) % (k - 2);
				if (stacksize < k - 2) stacksize++;
				// printf("STACKSIZE %d/%d\n", stacksize, (int)(k - 2));
				if (stacksize == (int)(k - 2)) {
					sll widthhigh = arr[ki].a;
					sll widthlow = arr[stack[stackend]].a;
					ull maybe;
					if (arr[i].a > widthhigh) widthhigh = arr[i].a;
					if (arr[j].a > widthhigh) widthhigh = arr[j].a;
					if (arr[i].a < widthlow) widthlow = arr[i].a;
					if (arr[j].a < widthlow) widthlow = arr[j].a;
					maybe = (widthhigh - widthlow) * (arr[j].b - arr[i].b);
					// printf("MAYBE %llu = (%llu-%llu) * %llu\n", maybe, (widthhigh), widthlow, (arr[j].b - arr[i].b));
					if (result == 0 || maybe < result) result = maybe;
				}
			}
		}
	}

	printf("%llu\n", result);

	return 0;
}
 
int main(void){
	int i, j;

	scanf("%llu%llu", &n, &k);
	for (i = 0; i < n; i++) {
		scanf("%lld%lld", &arr[i].a, &arr[i].b);
	}

	solve();
 
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:256:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%llu%llu", &n, &k);
  ^
./Main.c:258:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lld", &arr[i].a, &arr[i].b);
   ^