#include<stdio.h>
#include<stdlib.h>

typedef long long int int64;

const int mod=1000000007;

void run(void){
  int l;
  scanf("%d",&l);
  int64 *a=(int64 *)calloc(l+1,sizeof(int64));
  int64 *b=(int64 *)calloc(l+1,sizeof(int64));
  a[0]=1;
  b[0]=1;
  int i;
  for(i=1;i<=l;i++){
    a[i]=(2*a[i-1]*a[i-1]%mod*b[i-1]+b[i-1]*a[i-1]%mod*b[i-1])%mod;
    b[i]=((a[i-1]+b[i-1])*(a[i-1]+b[i-1])%mod+2*a[i-1]*b[i-1]%mod*b[i-1]%mod+b[i-1]*b[i-1]%mod*b[i-1])%mod;
  }
  int64 ans=0;
  int64 mul=1;
  for(i=l;i>=1;i--,mul=mul*3%mod){
    int64 c=a[i-1]+b[i-1];
    ans+=mul*c%mod*c%mod*c%mod;
  }
  ans=(ans+mul)%mod;
  printf("%lld\n",ans);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:10:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&l);
   ^