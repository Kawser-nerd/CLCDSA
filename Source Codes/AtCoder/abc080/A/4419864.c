#include <stdio.h>
int main(void){
	int n,a,b;
	scanf("%d%d%d",&n,&a,&b);
	if(a*n<=b) printf("%d\n",a*n);
	else printf("%d\n",b);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d",&n,&a,&b);
  ^