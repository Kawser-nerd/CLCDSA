#include<stdio.h>
int main(void) {
	long a, b;
	scanf("%ld%ld", &b, &a);
	if (a * b < 0) {
              printf("%ld\n", a - b - 1);
		}
	else {			
              printf("%ld\n", (a - b < 0) ? (b - a) : (a - b));
		}
		return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%ld%ld", &b, &a);
  ^