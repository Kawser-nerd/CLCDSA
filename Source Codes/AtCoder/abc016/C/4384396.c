#include<stdio.h>

int main(void){
	int N,M,i,j,k;
	scanf("%d %d",&N,&M);
	int A[M+1],B[M+1],F[N+1][N+1],FF[N+1][N+1];
	for(i=1;i<=M;i++) scanf("%d %d",&A[i],&B[i]);
	
	//????????????
	for(i=1;i<=N;i++){
		for(j=1;j<=N;j++) F[i][j]=FF[i][j]=0;
	}
	
	//??
	for(i=1;i<=M;i++) F[A[i]][B[i]]=F[B[i]][A[i]]=1;
	
	//?????
	for(i=1;i<=N;i++){
		for(j=1;j<=N;j++){
			//i?j??????
			if(F[i][j]){
				//j????i??????
				for(k=1;k<=N;k++){
					if(FF[i][k]==0) FF[i][k]=F[j][k];
				}
			}
		}
	}
	
	for(i=1;i<=N;i++){
		int count=0;
		for(j=1;j<=N;j++){
			if(FF[i][j]&&!F[i][j]&&i!=j) count++;
		}
		printf("%d\n",count);
	}
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d",&N,&M);
  ^
./Main.c:7:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for(i=1;i<=M;i++) scanf("%d %d",&A[i],&B[i]);
                    ^