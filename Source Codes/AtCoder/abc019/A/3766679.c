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
	long long int n,s,t,w, m, k,p,q,r=0;
	char str[30],str2[15],str3[15];
	int num[1200];
	scanf("%lld%lld%lld",&n,&m,&k);
	
	if (n>=m&&m>=k|| k >= m && m >= n) {
		printf("%lld\n",m);
	}
	else if (n >= k && k >= m || m >= k && k >= n) {
		printf("%lld\n", k);
	}
	else if (m >= n && n >= k|| k >= n && n >=m) {
		printf("%lld\n", n);
	}
	
	

} ./Main.c: In function ‘main’:
./Main.c:33:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld%lld",&n,&m,&k);
  ^