#include<stdio.h>

int main(){
	int N,A,B;
	scanf("%d%d%d",&N,&A,&B);
	if((B-A)%2==0)printf("Alice\n");
	else printf("Borys\n");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d",&N,&A,&B);
  ^