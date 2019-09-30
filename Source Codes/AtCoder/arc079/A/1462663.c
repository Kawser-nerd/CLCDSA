#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BIG 2000000007

#define MOD 1000000007
typedef unsigned long long ull;
typedef   signed long long sll;


#define N_MAX 200000
#define M_MAX 200000

ull n, m;
ull a[N_MAX];
ull b[N_MAX];

void swap_adj(ull *a, ull *b){
	ull tmp = *b;
	*b = *a;
	*a = tmp;
	return;
}

int comp(const void *a, const void *b){
	if (*(ull*)a < *(ull*)b) {
		return -1;
	} else if (*(ull*)a > *(ull*)b) {
		return +1;
	} else {
		return 0;
	}
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

int nibutan(ull x, int begin, int end){
	while (begin + 1 < end) {
		int med = (begin + end) / 2;
		if (b[med] < x) {
			begin = med;
		} else {
			end = med;
		}
	}
	if (b[begin] < x) {
		return begin;
	} else {
		return begin - 1;
	}
}

int solve(){
	int i, j;
	ull x = 0;

	for (i = 0; i < n; i++) {
		b[i] = BIG;
	}
	
	for (i = 0; i < n; i++) {
		if (!i) {
			b[0] = a[0];
			x++;
			continue;
		}
		int index = nibutan(a[i], 0, x);
		b[index + 1] = a[i];
		if (index + 1 == x) x++;

	}

	printf("%llu\n", x);

	return 0;
}

int main(void){
	ull i;

	scanf("%llu%llu", &n, &m);

	for (i = 0; i < m; i++) {
		ull x, y;
		scanf("%llu%llu", &x, &y);
		if (x == 1) {
			a[y - 1] = 1;
		}
		if (y == n) {
			b[x - 1] = 1;
		}
	}

	for (i = 0; i < n; i++) {
		if (a[i] && b[i]) {
			goto poss;
		}
	}
	printf("IM");
	poss:
	puts("POSSIBLE");

	// solve();

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:100:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%llu%llu", &n, &m);
  ^
./Main.c:104:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%llu%llu", &x, &y);
   ^