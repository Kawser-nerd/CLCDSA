#include<stdio.h>

int ketanowa(int i){
	int sum=0;
	
	while(i>0){
			sum=sum+i%10;
			i=i/10;
		}
	
	return sum;
}




int main(){
	
	int N,A,B,i,j,sum,total=0;
	scanf("%d%d%d",&N,&A,&B);
	
	for(i=1;i<=N;i++){
		
		sum=ketanowa(i);
		if(A<=sum&&sum<=B){
			total=total+i;
			
		}
		
		
	}
	
	
	
	printf("\n%d\n\n",total);
	
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:20:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d",&N,&A,&B);
  ^