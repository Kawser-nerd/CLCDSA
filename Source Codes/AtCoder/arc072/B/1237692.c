#include <stdio.h>

int main(void) {
	long long int X, Y;
	scanf("%lld%lld", &X, &Y);
	if (-1 <= X - Y && X - Y <= 1) 
		printf("Brown\n");
	else 
		printf("Alice\n");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld", &X, &Y);
  ^