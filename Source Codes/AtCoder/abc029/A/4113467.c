#include <stdio.h>

int main(void){
	char in[15];
	scanf("%s", in);
	printf("%ss\n", in);
	return 0;
} ./Main.c: In function �main�:
./Main.c:5:2: warning: ignoring return value of �scanf�, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s", in);
  ^