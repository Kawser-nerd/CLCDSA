#include<stdio.h>
int main(){
	
	int N,i,j,count=0;
	scanf("%d",&N);
	
	for(i=0;i<N;i++){
		
		for(j=0;j<N;j++){
			if(i*7+j*4==N){
			count++;
			}
		}
	}
	
	
	if(count>0){
	printf("\nYes\n\n");
	}else {
		printf("\nNo\n\n");
	}
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&N);
  ^