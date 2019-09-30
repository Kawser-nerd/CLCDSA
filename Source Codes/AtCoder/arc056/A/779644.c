#include <stdio.h>

int main(void) {

	long long int a, b, k, l;
	long long int sum = 0;

	scanf("%lld %lld %lld %lld", &a, &b, &k, &l);

	sum = k / l * b;
	if ((k % l )* a > b) {
		sum += b;
	} else {
		sum += (k % l) * a;
	}

	printf("%lld\n", sum);

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld %lld %lld %lld", &a, &b, &k, &l);
  ^