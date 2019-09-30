#include <stdio.h>
int main(void){
	int x;
	scanf("%d",&x);
	if(x<1200) printf("ABC\n");
	else printf("ARC\n");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&x);
  ^