#include<stdio.h>

typedef long long int int64;

void run(void){
  int64 n;
  scanf("%lld",&n);
  int64 sum=0;
  int64 k;
  for(k=1;k*k<n;k++) if(n%k==0) sum+=k+n/k;
  if(k*k==n) sum+=k;
  printf("%s\n",sum==2*n?"Perfect":sum<2*n?"Deficient":"Abundant");
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld",&n);
   ^