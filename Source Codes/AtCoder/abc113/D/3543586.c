#include <stdio.h>
int max(int a, int b){return a>b?a:b;}
int main(void){
    int h,w,k;
    scanf("%d%d%d",&h,&w,&k);
    long long dp[h+1][w+2],mod=1000000007,n[8]={1,2,3,5,8,13,21,24};
    for (int i=0; i<h+1; i++){
        for (int j=0; j<=w; j++){
            dp[i][j]=0;
        }
    }
    dp[0][0]=1;
    for (int i=1; i<h+1; i++){
        for (int j=0; j<w; j++){
            if (j==0){
                dp[i][j]=(dp[i][j]+dp[i-1][j]*n[max(0,w-2)])%mod;
                dp[i][j]=(dp[i][j]+dp[i-1][j+1]*n[max(0,w-3)])%mod;
            } else if (j==w-1){
                dp[i][j]=(dp[i][j]+dp[i-1][j]*n[max(0,w-2)])%mod;
                dp[i][j]=(dp[i][j]+dp[i-1][j-1]*n[max(0,w-3)])%mod;
            } else {
                dp[i][j]=(dp[i][j]+dp[i-1][j]*n[max(0,j-1)]*n[max(0,w-j-2)])%mod;
                dp[i][j]=(dp[i][j]+dp[i-1][j-1]*n[max(0,j-2)]*n[max(0,w-j-2)])%mod;
                dp[i][j]=(dp[i][j]+dp[i-1][j+1]*n[max(0,j-1)]*n[max(0,w-j-3)])%mod;
            }
        }
    }
    printf("%lld\n",dp[h][k-1]%mod);
	return 0 ;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d",&h,&w,&k);
     ^