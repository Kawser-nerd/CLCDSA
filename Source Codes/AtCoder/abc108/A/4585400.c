#include <stdio.h>

int main(void){
	int k;
	scanf("%d", &k);
	printf("%d\n", (k / 2) * ((k + 1) / 2));
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &k);
  ^