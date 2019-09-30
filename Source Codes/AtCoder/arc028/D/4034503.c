#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef long long int int64;

const int mod=1000000007;

void calc(int *a,int n,int m,int *res,int *dp){
  if(n<=1){
    memcpy(res,dp,sizeof(int)*(m+1));
    return;
  }
  int mid=n/2;
  memcpy(res,dp,sizeof(int)*(m+1));
  int i,j;
  for(i=0;i<mid;i++){
    int s=0;
    for(j=m;j>m-a[i];j--) s=(s+dp[j])%mod;
    for(j=m;j>=0;j--){
      int sub=dp[j];
      if(j-a[i]>=0) s=(s+dp[j-a[i]])%mod;
      dp[j]=s;
      s=(s-sub+mod)%mod;
    }
  }
  calc(a+mid,n-mid,m,res+mid*(m+1),dp);
  memcpy(dp,res,sizeof(int)*(m+1));
  for(i=mid;i<n;i++){
    int s=0;
    for(j=m;j>m-a[i];j--) s=(s+dp[j])%mod;
    for(j=m;j>=0;j--){
      int sub=dp[j];
      if(j-a[i]>=0) s=(s+dp[j-a[i]])%mod;
      dp[j]=s;
      s=(s-sub+mod)%mod;
    }
  }
  calc(a,mid,m,res,dp);
  return;
}

void run(void){
  int n,m,q;
  scanf("%d%d%d",&n,&m,&q);
  int *a=(int *)calloc(n,sizeof(int));
  int i;
  for(i=0;i<n;i++) scanf("%d",a+i);
  int *dp=(int *)calloc(m+1,sizeof(int));
  dp[0]=1;
  int *ans=(int *)calloc(n*(m+1),sizeof(int));
  calc(a,n,m,ans,dp);
  while(q--){
    int k,x;
    scanf("%d%d",&k,&x);
    printf("%d\n",ans[(k-1)*(m+1)+m-x]);
  }
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:45:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d",&n,&m,&q);
   ^
./Main.c:48:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++) scanf("%d",a+i);
                    ^
./Main.c:55:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&k,&x);
     ^