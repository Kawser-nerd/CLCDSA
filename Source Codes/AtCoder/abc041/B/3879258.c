#include<stdio.h>
int main() {
	long long int a, b, c;
	scanf("%lld%lld%lld", &a, &b, &c);
	a *= b;
	a %= 1000000007;
	a *= c;
	a %= 1000000007;
	printf("%lld", a);
} ./Main.c: In function ‘main’:
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld%lld", &a, &b, &c);
  ^