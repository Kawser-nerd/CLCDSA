/*
exit
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
 
#define BIG 2000000007
 
#define MOD 1000000007
typedef unsigned long long ull;
typedef   signed long long sll;

#define N_MAX 200
#define M_MAX 200
 
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
ull a[N_MAX];
// sll a[N_MAX];
ull b[M_MAX];
// ull dp[N_MAX][M_MAX + 1];
// char s[N_MAX + 1];
// char t[N_MAX + 1];
// char s[N_MAX][M_MAX + 1];
// hw arr[N_MAX];
// hwll arr[N_MAX];
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
 
ull min(ull x, ull y){
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

int ispalin(int x){
	return (x == 0) || ((x & -x) == x);
}

int bitlet(char c){
	return (1 << (c - 'a'));
}

ull solve(){
	int i, j, ki;

	// if (n == 1) {
	// 	if (a[0] < b[0] * 2) {
	// 		printf("%f\n", (double)(a[0] * a[0]) / 4);
	// 	} else {
	// 		printf("%llu\n", (a[0] - b[0]) * b[0]);
	// 	}
	// 	return 0;
	// }


	ull resultx8;

	ull speeds[N_MAX];
	for (i = 0; i < n; i++) {
		ull physicalMaxSpeed = (i > 0 ? speeds[i - 1] : 0) + a[i];
		ull currMaxSpeed = b[i];
		ull nextMaxSpeed = (i < n - 1 ? b[i + 1] : 0);
		ull endMaxSpeed = min(physicalMaxSpeed, min(currMaxSpeed, nextMaxSpeed));

		ull maxSpeed = endMaxSpeed;
		for (j = i; j >= 0; j--) {
			if (j == i || speeds[j] > maxSpeed) {
				speeds[j] = maxSpeed;
			} else {
				break;
			}
			maxSpeed += a[j];
		}
	}

	// for (i = 0; i < n; i++) printf("%llu\n", speeds[i]);

	resultx8 = 0;
	for (i = 0; i < n; i++) {
		ull left = (i > 0 ? speeds[i - 1] : 0);
		ull right = speeds[i];

		ull medx2 = (left + right + a[i]);

		ull leftTrx8 = (left * 2 + medx2) * (medx2 - left * 2);
		ull rightTrx8 = (right * 2 + medx2) * (medx2 - right * 2);
		ull cutx4 = (medx2 > b[i] * 2 ? (medx2 - b[i] * 2) * (medx2 - b[i] * 2) : 0);
		resultx8 += (leftTrx8 + rightTrx8 - cutx4 * 2);
	}

	printf("%f\n", (double)resultx8 / 8);
	return 0;
}
 
int main(void){
	int i, j;
	int x, y;

	// scanf("%llu", &n);
	scanf("%llu", &n);
	for (i = 0; i < n; i++) {
		scanf("%llu", &a[i]);
	}
	for (i = 0; i < n; i++) {
		scanf("%llu", &b[i]);
	}

	solve();
 
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:268:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%llu", &n);
  ^
./Main.c:270:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%llu", &a[i]);
   ^
./Main.c:273:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%llu", &b[i]);
   ^