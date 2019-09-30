#include<stdio.h>
#include<stdlib.h>

#define POS(i,j) ((i)*(m+1)+(j))
#define ADD(x,v) do{x+=(v);if(x>=mod) x-=mod;}while(0)

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
    for(j=m;j>m-a[i];j--) ADD(s,dp[j]);
    for(j=m;j>=0;j--){
      int sub=dp[j];
      if(j-a[i]>=0) ADD(s,dp[j-a[i]]);
      dp[j]=s;
      ADD(s,mod-sub);
    }
  }
  int *ans=(int *)calloc(n*(m+1),sizeof(int));
  for(i=0;i<n;i++){
    int s=0;
    for(j=0;j<=m;j++){
      int l=dp[j];
      ADD(l,mod-s);
      ans[POS(i,j)]=l;
      ADD(s,ans[POS(i,j)]);
      if(j-a[i]>=0)ADD(s,mod-ans[POS(i,j-a[i])]);
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
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d",&n,&m,&q);
   ^
./Main.c:12:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++) scanf("%d",a+i);
                    ^
./Main.c:39:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&k,&x);
     ^