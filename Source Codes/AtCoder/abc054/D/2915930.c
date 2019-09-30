#include <stdio.h>

int a[45];
int b[45];
int c[45];

int dp[45][405][405];

int min(int x,int y){
	if(x<y){return x;}
	else{return y;}
}

int main(){

	int N,Ma,Mb;

	scanf("%d %d %d",&N,&Ma,&Mb);

	int i,j,k;

	for(i=0;i<N;i++){
	scanf("%d %d %d",&a[i],&b[i],&c[i]);
	}

	for(i=0;i<=40;i++){
		for(j=0;j<=400;j++){
			for(k=0;k<=400;k++){
				dp[i][j][k]=114514;
			}
		}
	}

	dp[0][0][0]=0;

	for(i=0;i<N;i++){
		for(j=0;j<=400;j++){
			for(k=0;k<=400;k++){
				dp[i+1][j][k]=min(dp[i+1][j][k],dp[i][j][k]);
				if(j+a[i]<=400&&k+b[i]<=400){
				dp[i+1][j+a[i]][k+b[i]]=min(dp[i+1][j+a[i]][k+b[i]],dp[i][j][k]+c[i]);
				}
			}
		}
	}

	int ans=114514;

	for(i=1;;i++){
		if(Ma*i>400||Mb*i>400){break;}
		for(j=0;j<=N;j++){
		ans=min(ans,dp[j][Ma*i][Mb*i]);
		}
	}

	if(ans==114514){printf("-1\n");}
	else{printf("%d\n",ans);}

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:18:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d %d",&N,&Ma,&Mb);
  ^
./Main.c:23:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d %d",&a[i],&b[i],&c[i]);
  ^