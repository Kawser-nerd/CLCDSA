#include <stdio.h>
#include <string.h>
int main(void){
	int N,M,Q,i,j,k;
	scanf("%d%d%d",&N,&M,&Q);
	int l,r,p,q,x[501][501]={0},sum[501][501]={0},ans;
	for(i=0;i<M;i++){
		scanf("%d%d",&l,&r);
		x[l][r]++;
	}
	for(i=1;i<=N;i++){
		for(j=1;j<=N;j++)sum[i][j] = sum[i][j-1] + x[i][j];
	}
	
	for(i=0;i<Q;i++){
		scanf("%d%d",&p,&q);
		ans = 0;
		for(j=p;j<=q;j++)ans += sum[j][q]-sum[j][p-1];
		printf("%d\n",ans);
	}
	
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d",&N,&M,&Q);
  ^
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&l,&r);
   ^
./Main.c:16:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&p,&q);
   ^