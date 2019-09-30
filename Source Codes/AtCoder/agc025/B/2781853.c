#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

int64 modInverse(const int64 a,const int mod){
  int n=mod-2;
  int64 t=1;
  int64 s=a;
  while(n>0){
    if(n&0x01) t=t*s%mod;
    s=s*s%mod;
    n>>=1;
  }
  return t;
}

void run(void){
  int64 n,a,b;
  int64 k;
  scanf("%lld%lld%lld%lld",&n,&a,&b,&k);
  const int mod=998244353;
  int64 *comb=(int64 *)malloc(sizeof(int64)*(n+1));
  comb[0]=1;
  int i;
  for(i=1;i<=n;i++){
    comb[i]=comb[i-1]*(n+1-i)%mod*modInverse(i,mod)%mod;
  }
  int64 way=0;
  for(i=0;i<=n;i++){
    if(!(k-a*i>=0 && (k-a*i)%b==0 && (k-a*i)/b<=n)) continue;
    int j=(k-a*i)/b;
    way=(way+comb[i]*comb[j])%mod;
  }
  printf("%lld\n",way);
  return;
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:26:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lld%lld%lld",&n,&a,&b,&k);
   ^