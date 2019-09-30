#include <stdio.h>

int max(int a,int b){return a>b?a:b;}
int main(void){
    int w,n,k;
    scanf("%d%d%d",&w,&n,&k);
    int a[n],b[n];
    for (int i=0; i<n; i++){
        scanf("%d%d",&a[i],&b[i]);
    }
    int dp[w+1][n+1][n+1];
    for (int i=0; i<w+1; i++){
        for (int j=0; j<n+1; j++){
            for (int l=0; l<n+1; l++){
                dp[i][j][l]=0;
            }
        }
    }
    for (int i=1; i<w+1; i++){
        for (int j=1; j<n+1; j++){
            for (int l=1; l<n+1; l++){
                if (i>=a[l-1]){
                    dp[i][j][l]=max(dp[i-a[l-1]][j-1][l-1]+b[l-1],dp[i][j][l-1]);
                } else {
                    dp[i][j][l]=dp[i][j][l-1];
                }
            }
        }
    }
    printf("%d\n",dp[w][k][n]);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d",&w,&n,&k);
     ^
./Main.c:9:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d%d",&a[i],&b[i]);
         ^