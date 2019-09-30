#include <stdio.h>
int main(void){
	int k;
	scanf("%d",&k);
	//????????
	int oddnumber=(k+1)/2;
	//????????
	int evennumber=k/2;
	//?????????????
	printf("%d",oddnumber*evennumber);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&k);
  ^