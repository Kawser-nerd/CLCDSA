#include<stdio.h>


int f(int X){
	
	int sum=0;
	while(X>0){
		
		sum+=X%10;
		X/=10;
	}
	
	return sum;
}



int main(){
	
	int N;
	scanf("%d",&N);
	
	if(N%f(N)==0){
		
		printf("\nYes\n\n");
	}else {
		printf("\nNo\n\n");
	}
		
	
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:21:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&N);
  ^