#include<stdio.h>
#include<stdlib.h>

typedef long long int int64;

void run(void){
  int n;
  scanf("%d",&n);
  int *a=(int *)malloc(sizeof(int)*n);
  int i;
  for(i=0;i<n;i++) scanf("%d",a+i);
  const int mod=1000000007;
  int *inv=(int *)malloc(sizeof(int)*(n+1));
  int *invSum=(int *)malloc(sizeof(int)*(n+1));
  int fact=1;
  inv[1]=invSum[1]=1;
  for(i=2;i<=n;i++){
    inv[i]=mod-(int64)(mod/i)*inv[mod%i]%mod;
    invSum[i]=(inv[i]+invSum[i-1])%mod;
    fact=(int64)fact*i%mod;
  }
  int ans=0;
  for(i=0;i<n;i++) ans=(ans+(int64)a[i]*(invSum[n-i]+invSum[i+1]-1))%mod;
  ans=(int64)ans*fact%mod;
  printf("%d\n",ans);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:11:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++) scanf("%d",a+i);
                    ^