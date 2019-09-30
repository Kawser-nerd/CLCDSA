#include <stdio.h>

int main(void){
	unsigned long n;
	scanf("%ld", &n);
	printf("%ld\n", n - (1 - 2 * (n % 2)));
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%ld", &n);
  ^