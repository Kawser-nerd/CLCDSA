#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

int isPrime(int n){
  if(n<=1) return 0;
  int k;
  for(k=2;k*k<=n;k++) if(n%k==0) return 0;
  return 1;
}

void run(void){
  int n;
  scanf("%d",&n);
  const int mod=1000000007;
  int cnt=1;
  int i;
  for(i=1;i<=n;i++){
    if(!isPrime(i)) continue;
    int local=0;
    int t=n;
    while(t>=i){
      local+=t/i;
      t/=i;
    }
    cnt=(int64)cnt*(local+1)%mod;
  }
  printf("%d\n",cnt);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:20:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^