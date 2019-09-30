#include<stdio.h>
#include<string.h>

int main(){
	int N,t[105],M,P[105],x[105];
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%d",&t[i]);
	}
	scanf("%d",&M);
	for(int i=0;i<M;i++){
		scanf("%d%d",&P[i],&x[i]);
	}
	for(int i=0;i<M;i++){
		int res=0;
		for(int j=0;j<N;j++){
			if(P[i]!=j+1){
				res+=t[j];
			}
			else{
				res+=x[i];
			}
		}
		printf("%d\n",res);
		res=0;
	}
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&N);
  ^
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&t[i]);
   ^
./Main.c:10:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&M);
  ^
./Main.c:12:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&P[i],&x[i]);
   ^