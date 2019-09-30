#include<stdio.h>
#include<stdlib.h>

typedef long long int int64;

#define POS(i,j) ((i)*(b+1)+(j))

const int mod=1000000007;

int modPow(int r,int n){
  int t=1;
  int s=r;
  while(n>0){
    if(n&0x01) t=(int64)t*s%mod;
    s=(int64)s*s%mod;
    n>>=1;
  }
  return t;
}

int *fact=NULL;
int *iFact=NULL;
void init(const int n){
  fact=(int *)malloc(sizeof(int)*(n+1));
  iFact=(int *)malloc(sizeof(int)*(n+1));
  fact[0]=1;
  int i;
  for(i=1;i<=n;i++) fact[i]=(int64)i*fact[i-1]%mod;
  iFact[n]=modPow(fact[n],mod-2);
  for(i=n-1;i>=0;i--) iFact[i]=(int64)iFact[i+1]*(i+1)%mod;
  return;
}

int comb(int n,int k){
  if(!(0<=n && 0<=k && k<=n)) return 0;
  return (int64)fact[n]*iFact[k]%mod*iFact[n-k]%mod;
}

int n,a,b,c,d;
int *dp=NULL;

int calc(int x,int y){
  if(x==0) return 1;
  if(y<a) return 0;
  if(dp[POS(x,y)]>=0) return dp[POS(x,y)];
  int local=calc(x,y-1);
  int k;
  for(k=c;k<=d && k<=x/y;k++){
    int way=(int64)comb(x,k*y)*fact[k*y]%mod*modPow(iFact[y],k)%mod*iFact[k]%mod;
    local=(local+(int64)way*calc(x-k*y,y-1))%mod;
  }
  dp[POS(x,y)]=local;
  return local;
}

void run(void){
  scanf("%d%d%d%d%d",&n,&a,&b,&c,&d);
  init(n);
  dp=(int *)malloc(sizeof(int)*(n+1)*(b+1));
  int i;
  for(i=0;i<(n+1)*(b+1);i++) dp[i]=-1;
  int ans=calc(n,b);
  printf("%d\n",ans);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:57:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d%d%d",&n,&a,&b,&c,&d);
   ^