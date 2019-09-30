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
	long long int n, m, k,p,q;
	char str[30],str2[15],str3[15];
	scanf("%lld%lld%lld",&n,&m,&k);
	for (int i = k; i < 1000000; i++) {
		if (i%n == 0&&i%m==0) { printf("%lld\n", i); return 0; }
	}
	
	if (n==m&&m==k&&k==p) { printf("SAME"); }
	else {
		printf("DIFFERENT");
	}
} ./Main.c: In function ‘main’:
./Main.c:34:34: warning: format ‘%lld’ expects argument of type ‘long long int’, but argument 2 has type ‘int’ [-Wformat=]
   if (i%n == 0&&i%m==0) { printf("%lld\n", i); return 0; }
                                  ^
./Main.c:32:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld%lld",&n,&m,&k);
  ^