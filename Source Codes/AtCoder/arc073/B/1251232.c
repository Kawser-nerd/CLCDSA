#include<stdio.h>
#define MAX(a,b) (((a)>(b))?(a):(b))

long dp[100][101][301];

int main(int argc, char const *argv[]){
	long n,w,i,we,va,w1,j,k,max=0;
	scanf("%ld %ld",&n,&w);
	scanf("%ld %ld",&w1,&va);
	for(i=0;i<n;i++){
		for(j=0;j<=i+1;j++){
			for(k=0;k<=3*j;k++){
				dp[i][j][k]=-1;
			}
		}
	}
	dp[0][0][0]=0;
	dp[0][1][0]=va;
	for(i=1;i<n;i++){
		scanf("%ld %ld",&we,&va);
		dp[i][0][0]=0;
		for(j=1;j<=i+1;j++){
			for(k=0;k<=j*3;k++){
				if(k-(we-w1)<0 || dp[i-1][j-1][k-(we-w1)]==-1){
					if(dp[i-1][j][k]!=-1) dp[i][j][k]=dp[i-1][j][k];
				}else{
					dp[i][j][k]=dp[i-1][j-1][k-(we-w1)]+va;
					if(dp[i-1][j][k]!=-1) dp[i][j][k]=MAX(dp[i-1][j][k],dp[i][j][k]);
				}
			}
		}
	}
	for(i=0;i<=n;i++){
		for(j=0;j<=i*3;j++){
			if(w1*i+j>w) break;
			if(dp[n-1][i][j]!=-1) max=MAX(max,dp[n-1][i][j]);
		}
	}
	printf("%ld\n",max);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%ld %ld",&n,&w);
  ^
./Main.c:9:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%ld %ld",&w1,&va);
  ^
./Main.c:20:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%ld %ld",&we,&va);
   ^