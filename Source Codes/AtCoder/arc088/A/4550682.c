#include<stdio.h>
int main() {
	long long X, Y;
	//X = 1, Y = 1000000000000000000;
	//X = 1, Y = 10;
	scanf("%lld%lld", &X, &Y);
	long long ans = 1;
	while (X * 2 <= Y) {
		X = X * 2;
		ans++;
	}
	printf("%lld\n", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld", &X, &Y);
  ^