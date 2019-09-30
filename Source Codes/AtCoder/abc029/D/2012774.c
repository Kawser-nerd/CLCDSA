#include <stdio.h>
 
int main(void){
	int keta,count;
	int i,j;
	int num;	
	int N,orizin;
	scanf("%d",&N);
	orizin = N;
	
	keta=1;
	count =0;
	while(N != 0){
		num = N%10;
		N = N/10;
		
		if(num == 0){
			count += N*keta;
		}else if(num > 1){
			count += (N+1)*keta;
		}else if(num == 1){
			count += N*keta + orizin % keta+1;
		}
		keta=keta*10;
	}
	
	printf("%d\n",count);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&N);
  ^