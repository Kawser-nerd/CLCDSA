#include<stdio.h>
#include<stdlib.h>

typedef long long int int64;

const int mod=1000000007;

int *fact;
int *iFact;
void init(const int n){
  fact=(int *)calloc(n+1,sizeof(int));
  iFact=(int *)calloc(n+1,sizeof(int));
  fact[0]=1;
  int i;
  for(i=1;i<=n;i++) fact[i]=(int64)i*fact[i-1]%mod;
  int t=1;
  int a=fact[n];
  while(a>1){
    t=(int64)t*(mod-mod/a)%mod;
    a=mod%a;
  }
  iFact[n]=t;
  for(i=n-1;i>=0;i--) iFact[i]=(int64)iFact[i+1]*(i+1)%mod;
}

int comb(int n,int k){
  if(!(0<=k && k<=n)) return 0;
  return (int64)fact[n]*iFact[k]%mod*iFact[n-k]%mod;
}

void run(void){
  int n,m;
  scanf("%d%d",&n,&m);
  init(m+32);
  int ans=1;
  int t=n>0?n:-n;
  int k;
  for(k=2;k*k<=t;k++){
    if(t%k!=0) continue;
    int c=0;
    do{
      t/=k;
      c++;
    }while(t%k==0);
    ans=(int64)ans*comb(m-1+c,m-1)%mod;
  }
  if(t>1) ans=(int64)ans*m%mod;
  int local=0;
  for(k=(n>0?0:1);k<=m;k+=2) local=(local+comb(m,k))%mod;
  ans=(int64)ans*local%mod;
  printf("%d\n",ans);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:33:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&m);
   ^