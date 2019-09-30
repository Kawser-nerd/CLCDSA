#include <stdio.h>

int min(int a, int b){return a > b ? b : a;}

int main(void){
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	printf("%d\n", c / min(a, b));
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d %d", &a, &b, &c);
  ^