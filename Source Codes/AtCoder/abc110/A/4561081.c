#include <stdio.h>

int max(int a, int b){return a > b ? a : b;}

int main(void){
	int a, b, c;
	int sum = 0;
	scanf("%d %d %d", &a, &b, &c);
	printf("%d\n", max(a * 10 + b + c, max(b * 10 + a + c, c * 10 + a + b)));
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d %d", &a, &b, &c);
  ^