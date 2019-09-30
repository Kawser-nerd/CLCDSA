#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//???
long long int change_plus(long long int a) {
	if (a < 0) { return -a; }
	if (a >= 0) { return a; }
}
//????(?)
long long int big(long long int a, long long int b) {
	if (a >= b) {
		return a;
	}
	else {
		return b;
	}
}

//????(?)
long long int small(long long int a, long long int b) {
	if (a >= b) {
		return b;
	}
	else {
		return a;
	}
}

int main() {
	long long int n, m, k = 0;
	char str[5];
	scanf("%lld%lld",&n,&m);
	if (n == 2 || m == 2) { printf("No"); return 0; }
	if ((n == 4 || n == 6 || n == 9 || n == 11) && (m == 4 || m == 6 || m == 9 || m == 11)) { printf("Yes"); return 0; }
	if ((n == 1 || n == 3 || n == 5 || n == 7||n==8||n==10||n==12) && (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)) { printf("Yes"); return 0; }
	printf("No");
} ./Main.c: In function ‘main’:
./Main.c:32:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld",&n,&m);
  ^