#include<stdio.h>
long long int gcd(long long int a, long long int b) {
	long long int tmp;
	long long int r = 1;
	if (b > a) {
		tmp = a;
		a = b;
		b = tmp;
	}
	r = a % b;
	while (r != 0) {


		a = b;
		b = r;
		r = a % b;

	}
	return b;
}
int main() {
	long long int t, a, b, c, d, GCD, memo;
	scanf("%lld", &t);
	for (int i = 1; i <= t; i++) {
		scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
		if (b > d||a%b>c) { printf("No\n"); continue; }
		if (a < b) {
			printf("No\n"); continue;
		}
		if (a <= c) {
			if (a - b < 0) {
				printf("No\n"); continue;
			}
			else {
				printf("Yes\n"); continue;
			}
		}
		GCD = gcd(b, d);
		memo = (a%b) +((c-(a%b))/GCD)*GCD +GCD- b;

		if (memo < 0) {
			printf("No\n"); continue;
		}
		else {
			printf("Yes\n"); continue;
		}
	}
} ./Main.c: In function ‘main’:
./Main.c:23:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld", &t);
  ^
./Main.c:25:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
   ^