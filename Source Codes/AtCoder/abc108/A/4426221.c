#include <stdio.h>
int main(void){
	int k;
	scanf("%d",&k);
	if(k%2==0) printf("%d\n",(k/2)*(k/2));
	else printf("%d\n",(k/2+1)*(k/2));
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&k);
  ^