#include <stdio.h>

int main(void){
	int in;
	scanf("%d", &in);
	putchar('A');
	if(in < 1200)
		putchar('B');
	else
		putchar('R');
	printf("C\n");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &in);
  ^