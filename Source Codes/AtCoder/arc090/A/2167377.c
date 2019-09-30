#include <stdio.h>
int A[2][100],dp[2][100];
int max(int a,int b){return (a>b)?a:b;}
int main()
{
    int N,i,j;
    scanf("%d",&N);
    for(i=0;i<2;i++)
    {
        for(j=0;j<N;j++) scanf("%d",&A[i][j]);
    }
    for(i=0;i<2;i++)
    {
        for(j=0;j<N;j++)
        {
            dp[i][j]=A[i][j];
            if(i>0) dp[i][j]=max(dp[i][j],dp[i-1][j]+A[i][j]);
            if(j>0) dp[i][j]=max(dp[i][j],dp[i][j-1]+A[i][j]);
        }
    }
    printf("%d\n",dp[1][N-1]);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&N);
     ^
./Main.c:10:26: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         for(j=0;j<N;j++) scanf("%d",&A[i][j]);
                          ^