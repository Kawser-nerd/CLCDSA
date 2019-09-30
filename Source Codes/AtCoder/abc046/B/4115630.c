#include <stdio.h>

int main(void){
	int n, k;
	unsigned long res = 1;
	scanf("%d %d", &n, &k);
	res = k;
	for(int i = 1; i < n; i++)
		res *= k - 1;
	printf("%ld\n", res);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d", &n, &k);
  ^