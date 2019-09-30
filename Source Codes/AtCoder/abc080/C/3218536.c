#include<stdio.h>

int main(){
	int N,ans=-1000000000;
	scanf("%d",&N);
	int F[N][10];
	for(int i=0;i<N;i++){
		for(int j=0;j<10;j++)scanf("%d",&F[i][j]);
	}
	int P[N][11];
	for(int i=0;i<N;i++){
		for(int j=0;j<11;j++)scanf("%d",&P[i][j]);
	}
	
	for(int k=1;k<=1023;k++){
		int bit=k;
		int c[N];
		int tmp=0;
		for(int i=0;i<N;i++)c[i]=0;
		
		for(int t=0;t<10;t++){
			int op=bit%2;
			bit/=2;
			if(op==0)continue;
			for(int i=0;i<N;i++){
				if(F[i][t]==1)c[i]++;
			}
		}
		for(int i=0;i<N;i++)tmp+=P[i][c[i]];
		if(tmp>ans)ans=tmp;
	}
	printf("%d\n",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&N);
  ^
./Main.c:8:24: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(int j=0;j<10;j++)scanf("%d",&F[i][j]);
                        ^
./Main.c:12:24: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(int j=0;j<11;j++)scanf("%d",&P[i][j]);
                        ^