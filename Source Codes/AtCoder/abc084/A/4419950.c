#include <stdio.h>
int main(void){
	int m;
	scanf("%d",&m);
	printf("%d\n",(24-m)+24);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&m);
  ^