#include<stdio.h>

int main(){
    int n,k,t,dp[8][128]={0},i,j,x;
    scanf("%d%d",&n,&k);
    for(i = 1;i <= n;i++){
        for(j = 1;j <= k;j++){
            scanf("%d",&t);
            if(i == 1){dp[i][t]=1;continue;}
            for(x = 0;x < 128;x++){
                if(!(dp[i-1][x])){continue;}
                dp[i][(x^t)]=1;
            }
        }
    }
    if(dp[n][0]){printf("Found\n");}else{printf("Nothing\n");}
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&n,&k);
     ^
./Main.c:8:13: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
             scanf("%d",&t);
             ^