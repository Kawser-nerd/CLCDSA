#include <stdio.h>
#include <string.h>

#define ABS(a) ((a)<0?-(a):(a))
#define MIN(a,b) ((a)<(b)?(a):(b))


int dp[128][256];
int a[128];
int D,I,M,N;

int solve() {
  int i,j,v,k,need,ans,dist;
  memset(dp,63,sizeof(dp));
  for(i=0;i<256;i++) dp[0][i]=ABS(a[0]-i);
  for(i=1;i<N;i++) {
    for(j=0;j<256;j++) {
      /* assume last number was j */
      v=dp[i-1][j];
      /* delete number at position i, making j the last seen number */
      dp[i][j]=MIN(dp[i][j],v+D);
      for(k=0;k<256;k++) {
        /* change number from a[i] to k AND insert enough */
        dist=ABS(j-k);
        if(M>0) need=(dist-1)/M;
        else {
          /* change only */
          if(ABS(j-k)<=M) dp[i][k]=MIN(dp[i][k],v+ABS(a[i]-k));
          continue;
        }
        if(need<0) need=0;
        dp[i][k]=MIN(dp[i][k],v+need*I+ABS(a[i]-k));
      }
    }
  }
  ans=1000000000;
  for(i=0;i<256;i++) ans=MIN(ans,dp[N-1][i]);
  return ans;
}

int main() {
  int cases,caseno=1,i;
  scanf("%d",&cases);
  while(cases--) {
    scanf("%d %d %d %d",&D,&I,&M,&N);
    for(i=0;i<N;i++) scanf("%d",&a[i]);
    printf("Case #%d: %d\n",caseno++,solve());
  }
  return 0;
}
