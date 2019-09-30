#include<stdio.h>
int main(void){
	int N,M,C;
	scanf("%d%d%d",&N,&M,&C);
	int B[M];
	int a,b;
	for(a=0;a<M;a++){
		scanf("%d",&B[a]);
	}
	int A[M];
	int correct=0;
	int sum=0;
	for(a=0;a<N;a++){
		for(b=0;b<M;b++){
			scanf("%d",&A[b]);
			sum+=A[b]*B[b];
		}
		sum+=C;
		if(sum>0){
			correct++;
		}
		sum=0;
	}
	printf("%d",correct);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d",&N,&M,&C);
  ^
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&B[a]);
   ^
./Main.c:15:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%d",&A[b]);
    ^