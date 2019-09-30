#include <stdio.h>
int main(void){
	char d[3];
	scanf("2017/01/%s",d);
	printf("2018/01/%s\n",d);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("2017/01/%s",d);
  ^