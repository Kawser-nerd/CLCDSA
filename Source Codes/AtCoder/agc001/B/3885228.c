#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main() {
	long long int n, x, result = 0,tmp;
	scanf("%lld%lld", &n, &x);
	result = n;
	n = n - x;
	while (n != 0) {
		if (n%x != 0) { result += 2 * x*(n / x); }
		else { result += (2 * x*(n / x)-x);printf("%lld",result); return 0; }
		tmp = n%x;
		n = x;
		x = tmp;
	}
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld", &n, &x);
  ^