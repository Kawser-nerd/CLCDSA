#include <stdio.h>
int main(void){
    int N;
    scanf("%d",&N);
    int a[N];
    for(int i=0;i<N;i++)scanf("%d",&a[i]);
    int dp[N];
    int ans=0;
    for(int i=0;i<N;i++){
        dp[i]=1;
        for(int j=0;j<i;j++){
            if(a[j]<a[i]&&dp[i]<dp[j]+1)dp[i]=dp[j]+1;
        }
        if(dp[i]>ans)ans=dp[i];
    }
    printf("%d\n",N-ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&N);
     ^
./Main.c:6:25: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     for(int i=0;i<N;i++)scanf("%d",&a[i]);
                         ^