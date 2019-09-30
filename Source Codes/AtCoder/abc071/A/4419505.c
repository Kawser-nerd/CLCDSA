#include <stdio.h>
int main(void){
	int x,a,b;
	scanf("%d%d%d",&x,&a,&b);
	if(abs(a-x)<abs(b-x)) printf("A\n");
	else printf("B\n");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: implicit declaration of function ‘abs’ [-Wimplicit-function-declaration]
  if(abs(a-x)<abs(b-x)) printf("A\n");
     ^
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d",&x,&a,&b);
  ^