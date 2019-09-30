#include<stdio.h>
#include<stdlib.h>
int main(void){
	int N,K,X,Y,sum;
	scanf("%d",&N);
	scanf("%d",&K);
	scanf("%d",&X);
	scanf("%d",&Y);
	if(N<=K){
	sum=N*X;
	}else{
		sum=K*X+Y*(N-K);	
		}
	printf("%d\n",sum);
	return 0;	
	
}