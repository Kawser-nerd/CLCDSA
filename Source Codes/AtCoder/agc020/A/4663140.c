#include <stdio.h>
#include <stdlib.h>
int main(void){
	int N,A,B;
	scanf("%d%d%d",&N,&A,&B);
	if((B-A-1)%2==1)	printf("Alice");
	else printf("Borys");
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d",&N,&A,&B);
  ^