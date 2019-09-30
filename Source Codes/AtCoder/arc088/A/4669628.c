#include <stdio.h>



int main() {
	long long x, y, c, count = 0;
	scanf("%lld %lld", &x, &y);
	
	c = x;

	while (c <= y) {
		count++;
		c = 2 * c;
	}
	
	printf("%lld\n", count);

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld %lld", &x, &y);
  ^