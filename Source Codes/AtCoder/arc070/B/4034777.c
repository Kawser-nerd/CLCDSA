#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int calc(int *a,int n,int k,char *dp){
  if(n==1){
    if(a[0]>=k) return 0;
    for(int i=k-1;i>=k-a[0];i--) if(dp[i]) return 0;
    return 1;
  }
  int m=n/2;
  char *save=(char *)calloc(k,sizeof(char));
  memcpy(save,dp,k);
  int i,j;
  for(i=m;i<n;i++){
    if(a[i]>=k) continue;
    for(j=k-1;j>=a[i];j--) dp[j]|=dp[j-a[i]];
  }
  int cnt=calc(a,m,k,dp);
  memcpy(dp,save,k);
  free(save);
  for(i=0;i<m;i++){
    if(a[i]>=k) continue;
    for(j=k-1;j>=a[i];j--) dp[j]|=dp[j-a[i]];
  }
  cnt+=calc(a+m,n-m,k,dp);
  return cnt;
}

void run(void){
  int n,k;
  scanf("%d%d",&n,&k);
  int *a=(int *)calloc(n,sizeof(int));
  for(int i=0;i<n;i++) scanf("%d",a+i);
  char *dp=(char *)calloc(k,sizeof(char));
  dp[0]=1;
  int ans=calc(a,n,k,dp);
  printf("%d\n",ans);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:32:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&k);
   ^
./Main.c:34:24: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(int i=0;i<n;i++) scanf("%d",a+i);
                        ^