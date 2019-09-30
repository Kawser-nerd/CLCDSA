#include<stdio.h>
#include<stdlib.h>

typedef long long int int64;

const int mod=1000000007;

void run(void){
  int n;
  scanf("%d",&n);
  int *a=(int *)calloc(n,sizeof(int));
  int i;
  for(i=0;i<n;i++) scanf("%d",a+i);
  int *inv=(int *)calloc(n+1,sizeof(int));
  int *invSum=(int *)calloc(n+1,sizeof(int));
  inv[1]=invSum[1]=1;
  for(i=2;i<=n;i++){
    inv[i]=(int64)(mod-mod/i)*inv[mod%i]%mod;
    invSum[i]=(inv[i]+invSum[i-1])%mod;
  }
  int sum=0;
  for(i=0;i<n;i++){
    sum=(sum+(int64)a[i]*(invSum[n-i]+invSum[i+1]-1))%mod;
  }
  for(i=1;i<=n;i++) sum=(int64)sum*i%mod;
  printf("%d\n",sum);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:10:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:13:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++) scanf("%d",a+i);
                    ^