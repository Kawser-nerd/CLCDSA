#include <stdio.h>
int main(void){
	int a,b,x;
	scanf("%d%d%d",&a,&b,&x);
	if(x>=a && x-a<b) printf("YES\n");
	else printf("NO\n");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d",&a,&b,&x);
  ^