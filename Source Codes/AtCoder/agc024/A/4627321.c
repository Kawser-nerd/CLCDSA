#include<stdio.h>

typedef long long int int64;

void run(void){
  int64 a,b,c,k;
  scanf("%lld%lld%lld%lld",&a,&b,&c,&k);
  printf("%lld\n",k%2==0?a-b:b-a);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lld%lld%lld",&a,&b,&c,&k);
   ^