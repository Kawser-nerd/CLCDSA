#include <stdio.h>

int min(int a,int b){
	if(a<=b){return a;}
	else{return b;}
}

int a[45];
int b[45];
int c[45];
int dp[45][415][415];

int main(){

	int N,Ma,Mb;

	scanf("%d %d %d",&N,&Ma,&Mb);

	int i,j,k;

	for(i=0;i<N;i++){
		scanf("%d %d %d",&a[i],&b[i],&c[i]);
	}

	for (i = 0; i <= 40; i++) {
		for (j = 0; j <= 400; j++) {
			for (k = 0; k <= 400; k++) {
				dp[i][j][k] = 10000;
			}
		}
	}

	dp[0][0][0]=0;

	for(i=0;i<N;i++){
		for(j=0;j<=400;j++){
			for(k=0;k<=400;k++){
				if(dp[i][j][k]==10000){continue;}
				dp[i+1][j][k]=min(dp[i+1][j][k],dp[i][j][k]);
				dp[i+1][j+a[i]][k+b[i]]=min(dp[i+1][j+a[i]][k+b[i]],dp[i][j][k]+c[i]);
			}
		}
	}

	int ans=10000;
	for(i=1;;i++){
		if(Ma*i>400||Mb*i>400){break;}
		ans=min(ans,dp[N][Ma*i][Mb*i]);
	}

	if(ans==10000){printf("-1\n");}
	else{
	printf("%d\n",ans);
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:17:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d %d",&N,&Ma,&Mb);
  ^
./Main.c:22:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %d",&a[i],&b[i],&c[i]);
   ^