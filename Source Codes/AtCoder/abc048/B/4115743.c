#include <stdio.h>

int main(void){
	unsigned long a, b, x;
	scanf("%ld %ld %ld", &a, &b, &x);
	printf("%ld\n", b / x - a / x + (a % x ? 0 : 1));
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%ld %ld %ld", &a, &b, &x);
  ^