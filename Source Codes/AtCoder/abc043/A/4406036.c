#include <stdio.h>
int main(void){
	int n,ame=0;
	scanf("%d",&n);
	while(n!=0){
		ame+=n;
		n--;
	}
	printf("%d\n",ame);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^