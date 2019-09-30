#include <stdio.h>
int main(void){
	int n,x,i=0;
	scanf("%d%d",&n,&x);
	if(x>n-x) printf("%d\n",n-x);
	else printf("%d\n",x-1);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&n,&x);
  ^