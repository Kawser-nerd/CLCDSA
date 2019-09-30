#include <stdio.h>
int max(int a,int b){return a>b?a:b;}
int main(void){
    int n,m,i,j,data[10]={0,2,5,5,4,5,6,3,7,6},len;
    int ans[5000];
    scanf("%d%d",&n,&m);
    int dp[n+1],a[m],b[m];
    for(i=0;i<m;i++)scanf("%d",&a[i]);
    for(i=0;i<m-1;i++)for(j=0;j<m-i-1;j++)if(a[j]<a[j+1]){int t=a[j];a[j]=a[j+1];a[j+1]=t;}
    for(i=0;i<m;i++)b[i]=data[a[i]];
    dp[0]=0;
    for(i=1;i<=n;i++){
        dp[i]=-2100000000;
        for(j=0;j<m;j++)if(i-b[j]>=0)dp[i]=max(dp[i],dp[i-b[j]]+1);
    }
    len=dp[n];
    for(i=0;i<len;i++)for(j=0;j<m;j++){
      if(n>=b[j]&&dp[n-b[j]]==dp[n]-1){
        ans[i]=a[j];
        n-=b[j];
        break;
      }
    }
    for(i=0;i<len;i++)printf("%d",ans[i]);
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&n,&m);
     ^
./Main.c:8:21: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     for(i=0;i<m;i++)scanf("%d",&a[i]);
                     ^