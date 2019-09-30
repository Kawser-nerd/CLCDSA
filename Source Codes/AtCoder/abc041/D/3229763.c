#include<stdio.h>
#include<stdlib.h>

typedef long long int int64;
#define POS(i,j) ((i)*n+(j))

int n;
int d[256];
int64 *dp=NULL;
int64 calc(int bit){
  if(dp[bit]!=-1) return dp[bit];
  int64 res=0;
  int i;
  for(i=0;i<n;i++){
    if(((bit>>i)&0x01)==0) continue;
    int j;
    for(j=0;j<n;j++){
      if(((bit>>j)&0x01)==0 && d[POS(i,j)]==1) break;
    }
    if(j==n) res+=calc(bit^(1<<i));
  }
  dp[bit]=res;
  return res;
}

void run(void){
  int m;
  scanf("%d%d",&n,&m);
  int i;
  for(i=0;i<n*n;i++) d[i]=0;
  for(i=0;i<m;i++){
    int x,y;
    scanf("%d%d",&x,&y);
    x--;y--;
    d[POS(x,y)]=1;
  }
  dp=(int64 *)malloc(sizeof(int64)*(1<<n));
  for(i=0;i<(1<<n);i++) dp[i]=-1;
  dp[0]=1;
  int64 ans=calc((1<<n)-1);
  printf("%lld\n",ans);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:28:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&m);
   ^
./Main.c:33:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&x,&y);
     ^