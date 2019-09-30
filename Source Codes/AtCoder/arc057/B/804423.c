#include <stdio.h>
int main(void){
  int n,i,j,sum,kari,ans;//sum?????????
  long long int k,count=0;
  int a[2000];
  scanf("%d%lld",&n,&k);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
    count+=a[i];
  }
  long long int dp[2001];
  if(k==0){
    printf("0\n");
    return 0;
  }
  if(k==count){
    printf("1\n");
    return 0;
  }
  for(i=0;i<2001;i++){
    dp[i]=-1;
  }
  dp[0]=0;
  dp[1]=1;
  sum=a[0];
  ans=1;
  for(i=1;i<n;i++){//i+1??
    for(j=ans;j>0;j--){
      kari=dp[j]*a[i]/sum+1;
      //???????*???????????????=??????????????????
      if(kari+dp[j]<=k&&(dp[j+1]==-1||dp[j+1]>kari+dp[j])){//????K??????dp[j+1]???????????????????
        if(dp[j+1]==-1){
          ans+=1;
        }
        dp[j+1]=kari+dp[j];
      }
    }
    sum+=a[i];
    for(j=0;dp[j]!=-1;j++){
    //  printf("%lld ",dp[j]);
    }
    //printf("\n");
  }
  printf("%d\n",ans);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%lld",&n,&k);
   ^
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&a[i]);
     ^