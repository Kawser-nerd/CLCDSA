#include<stdio.h>
#include<stdlib.h>
#include<string.h>

const int mod=1000000007;

#define ADD(x,a) do{x+=(a);if(x>=mod) x-=mod;}while(0)
#define SUB(x,a) do{x+=mod-(a);if(x>=mod) x-=mod;}while(0)

void trans(int *dp,int m,int a){
  int sum=0;
  int i;
  for(i=m;i>=m-a;i--) ADD(sum,dp[i]);
  for(i=m;i>=0;i--){
    int v=sum;
    SUB(sum,dp[i]);
    if(i-a-1>=0) ADD(sum,dp[i-a-1]);
    dp[i]=v;
  }
}

void calc(int *a,int n,int m,int *dp,int *ans){
  if(n<=1){
    memcpy(ans,dp,sizeof(int)*(m+1));
    return;
  }
  int k=n/2;
  int *save=(int *)calloc(m+1,sizeof(int));
  memcpy(save,dp,sizeof(int)*(m+1));
  int i;
  for(i=k;i<n;i++) trans(dp,m,a[i]);
  calc(a,k,m,dp,ans);
  memcpy(dp,save,sizeof(int)*(m+1));
  free(save);
  for(i=0;i<k;i++) trans(dp,m,a[i]);
  calc(a+k,n-k,m,dp,ans+(m+1)*k);
}

void run(void){
  int n,m,q;
  scanf("%d%d%d",&n,&m,&q);
  int *a=(int *)calloc(n,sizeof(int));
  for(int i=0;i<n;i++) scanf("%d",a+i);
  int *ans=(int *)calloc(n*(m+1),sizeof(int));
  int *dp=(int *)calloc(m+1,sizeof(int));
  dp[0]=1;
  calc(a,n,m,dp,ans);
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
./Main.c:41:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d",&n,&m,&q);
   ^
./Main.c:43:24: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(int i=0;i<n;i++) scanf("%d",a+i);
                        ^
./Main.c:50:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&k,&x);
     ^