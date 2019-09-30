#include <stdio.h>
int main(void){
	char x[2],y[2];
	scanf("%s%s",x,y);
	if(x[0]-0x10<y[0]-0x10) printf("<\n");
	else if(x[0]-0x10>y[0]-0x10) printf(">\n");
	else printf("=\n");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s%s",x,y);
  ^