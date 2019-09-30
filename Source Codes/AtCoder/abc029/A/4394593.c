#include <stdio.h>
int main(void){
	char str[256];
	scanf("%s",str);
	printf("%ss\n",str);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",str);
  ^