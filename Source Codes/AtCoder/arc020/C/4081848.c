#include<stdio.h>
#include<stdlib.h>

typedef long long int int64;

int calc(int r,int n,int mod){
  if(n==1) return 1%mod;
  if(n%2) return (1+(int64)r*calc(r,n-1,mod))%mod;
  return (int64)(1+r)*calc((int64)r*r%mod,n/2,mod)%mod;
}

int modPow(int r,int n,int mod){
  int t=1%mod;
  int s=r%mod;
  while(n){
    if(n&1) t=(int64)t*s%mod;
    s=(int64)s*s%mod;
    n>>=1;
  }
  return t;
}

void run(void){
  int n;
  scanf("%d",&n);
  int *a=(int *)calloc(n,sizeof(int));
  int *l=(int *)calloc(n,sizeof(int));
  int i;
  for(i=0;i<n;i++) scanf("%d%d",a+i,l+i);
  int mod;
  scanf("%d",&mod);
  int ans=0;
  int mul=1;
  for(i=n-1;i>=0;i--){
    int t=a[i];
    int d=1%mod;
    while(t>0){
      t/=10;
      d=(int64)d*10%mod;
    }
    ans=(ans+(int64)mul*calc(d,l[i],mod)%mod*a[i]%mod)%mod;
    mul=(int64)mul*modPow(d,l[i],mod)%mod;
  }
  printf("%d\n",ans);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:25:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:29:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++) scanf("%d%d",a+i,l+i);
                    ^
./Main.c:31:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&mod);
   ^