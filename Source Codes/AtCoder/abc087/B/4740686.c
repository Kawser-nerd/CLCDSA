#include<stdio.h>
int main(){
	
	int i,j,k,count=0,A,B,C,X;
	scanf("%d",&A);
	scanf("%d",&B);
	scanf("%d",&C);
	scanf("%d",&X);
	
	for(i=0;i<=A;i++){
		
	
	for(j=0;j<=B;j++){
		
	
	for(k=0;k<=C;k++){
		
		if(X==500*i+100*j+50*k){
			count++;
	}
	}
	}
	}
	
	printf("\n%d\n\n",count);
	
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&A);
  ^
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&B);
  ^
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&C);
  ^
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&X);
  ^