#include<stdio.h>
int main(void){
	
	int k=1,ninoinsi=0,N;
	scanf("%d",&N);
	
	while(N>=k){
		k=k*2;
		ninoinsi++;
	}
		
	printf("\n%d\n\n",k/2);
	
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&N);
  ^