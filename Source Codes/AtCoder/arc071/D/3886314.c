#include<stdio.h>
#include<stdlib.h>

typedef long long int int64;

const int mod=1000000007;

void run(void){
  int n;
  scanf("%d",&n);
  int *dp=(int *)calloc(n+1,sizeof(int));
  dp[0]=1;
  dp[1]=n;
  int sum=n-1;
  int i;
  for(i=2;i<=n;i++){
    int local=(dp[i-1]+(int64)(n-1)*(n-1)+sum)%mod;
    dp[i]=local;
    sum=((int64)sum-1+dp[i-2])%mod;
  }
  printf("%d\n",dp[n]);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:10:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^