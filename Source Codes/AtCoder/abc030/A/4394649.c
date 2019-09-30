#include <stdio.h>
int main(void){
	int a,b,c,d;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	if((double)b/a>(double)d/c) printf("TAKAHASHI\n");
	else if((double)b/a==(double)d/c) printf("DRAW\n");
	else printf("AOKI\n");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d%d",&a,&b,&c,&d);
  ^