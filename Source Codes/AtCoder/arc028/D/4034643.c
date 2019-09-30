#include<stdio.h>
#include<stdlib.h>

#define POS(i,j) ((i)*(m+1)+(j))

void run(void){
  int n,m,q;
  scanf("%d%d%d",&n,&m,&q);
  int *a=(int *)calloc(n,sizeof(int));
  int i,j;
  for(i=0;i<n;i++) scanf("%d",a+i);
  const int mod=1000000007;
  int *dp=(int *)calloc(m+1,sizeof(int));
  dp[0]=1;
  for(i=0;i<n;i++){
    int s=0;
    for(j=m;j>m-a[i];j--) s=(s+dp[j])%mod;
    for(j=m;j>=0;j--){
      int sub=dp[j];
      if(j-a[i]>=0) s=(s+dp[j-a[i]])%mod;
      dp[j]=s;
      s=(s-sub+mod)%mod;
    }
  }
  int *ans=(int *)calloc(n*(m+1),sizeof(int));
  for(i=0;i<n;i++){
    int s=0;
    for(j=0;j<=m;j++){
      ans[POS(i,j)]=(dp[j]-s+mod)%mod;
      s=(s+ans[POS(i,j)])%mod;
      if(j-a[i]>=0) s=(s-ans[POS(i,j-a[i])]+mod)%mod;
    }
  }
  while(q--){
    int k,x;
    scanf("%d%d",&k,&x);
    printf("%d\n",ans[POS(k-1,m-x)]);
  }
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d",&n,&m,&q);
   ^
./Main.c:11:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++) scanf("%d",a+i);
                    ^
./Main.c:36:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&k,&x);
     ^