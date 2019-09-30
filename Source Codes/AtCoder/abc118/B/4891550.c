#include <stdio.h>
int main(void){
	int N,M;
	int i,j,temp;
	scanf("%d %d",&N,&M);
	int K[30];
	int A[31]={};
	for(i=0;i<N;i++){
		scanf("%d",&K[i]);
		for(j=0;j<K[i];j++){
			scanf("%d",&temp);
			A[temp]++;
		}
	}
	int ans = 0;
	for(i=1;i<M+1;i++){
		if(A[i]==N){
			ans++;
		}
	}
	printf("%d",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d",&N,&M);
  ^
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&K[i]);
   ^
./Main.c:11:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%d",&temp);
    ^