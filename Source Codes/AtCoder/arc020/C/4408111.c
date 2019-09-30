#include<stdio.h>
#include<stdlib.h>

typedef long long int int64;

int64 calc(int64 r,int64 n,int mod){
  if(n==1) return 1%mod;
  if(n&1){
    return (1+r*calc(r,n-1,mod))%mod;
  }
  return (1+r)*calc(r*r%mod,n/2,mod)%mod;
}

int64 modPow(int64 r,int64 n,int mod){
  int64 t=1;
  int64 s=r;
  while(n>0){
    if(n&1) t=t*s%mod;
    s=s*s%mod;
    n>>=1;
  }
  return t;
}

void run(void){
  int n;
  scanf("%d",&n);
  int64 *a=(int64 *)calloc(n,sizeof(int64));
  int64 *l=(int64 *)calloc(n,sizeof(int64));
  int i;
  for(i=0;i<n;i++) scanf("%lld%lld",a+i,l+i);
  int mod;
  scanf("%d",&mod);
  int64 ans=0;
  for(i=0;i<n;i++){
    int64 r=1%mod;
    int64 t=a[i];
    while(t>0){
      r=r*10%mod;
      t/=10;
    }
    ans=ans*modPow(r,l[i],mod)%mod;
    ans=(ans+calc(r,l[i],mod)*a[i])%mod;
  }
  printf("%lld\n",ans);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:27:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:31:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++) scanf("%lld%lld",a+i,l+i);
                    ^
./Main.c:33:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&mod);
   ^