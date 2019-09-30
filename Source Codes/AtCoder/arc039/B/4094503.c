#include<stdio.h>
#include<stdlib.h>

typedef long long int int64;

const int mod=1000000007;

int comb(int n,int k){
  if(k>n/2) k=n-k;
  int nu=1;
  int de=1;
  for(int i=1;i<=k;i++){
    nu=(int64)nu*(n+1-i)%mod;
    de=(int64)de*i%mod;
  }
  int t=1;
  while(de>1){
    t=(int64)t*(mod-mod/de)%mod;
    de=mod%de;
  }
  return (int64)nu*t%mod;
}

void run(void){
  int n,k;
  scanf("%d%d",&n,&k);
  printf("%d\n",k<n?comb(n+k-1,n-1):comb(n,k%n));
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:26:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&k);
   ^