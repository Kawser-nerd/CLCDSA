#include <stdio.h>

#define min(a, b) ((a) > (b) ? (b) : (a))

int main(void){
	int n, x;
	scanf("%d %d", &n, &x);
	printf("%d\n", min(x - 1, n - x));
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d", &n, &x);
  ^