#include<stdio.h>

int main() {
	long long int a, b, c, d, n, m=0, result = 100000;
	
	scanf("%lld", &n);
	for (int i = 0; i <= n;i++) {
		a = i;
		m = 0;
		while (a > 0) {
			m += a % 6;
			a /= 6;
		}
		a = n - i;
		while (a > 0) {
			m += a % 9;
			a /= 9;
		}
		if (m < result) { result = m; }
	}
	
	printf("%lld", result);
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld", &n);
  ^