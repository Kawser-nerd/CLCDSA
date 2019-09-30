#include<stdio.h>
long long gcd(long long a,long long b){return b?gcd(b,a%b):a;}
int main(){
	long long n,m;
	scanf("%lld %lld",&n,&m);
	printf("%lld\n",3*(n-gcd(n,m)));
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld %lld",&n,&m);
  ^