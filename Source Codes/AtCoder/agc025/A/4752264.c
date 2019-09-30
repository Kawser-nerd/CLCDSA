#include<stdio.h>

int ketanowa(int N){
	
	int sum=0;
	while(N>0){
		
		sum+=N%10;
		N/=10;
	}
	
	return sum;
}

int main(){
	
	int N,A,B,sumA,sumB,i,sum=0,ans=100;
	scanf("%d",&N);
	
	for(i=1;i<N;i++){
		sumA=ketanowa(i);
		sumB=ketanowa(N-i);
		
		sum=sumA+sumB;
		
		if(ans>sum){
			ans=sum;
			
		}
		
	}
	
	printf("\n%d\n\n",ans);
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:18:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&N);
  ^