#include<stdio.h>
#include<stdlib.h>

typedef long long int int64;

int64 gcd(int64 a,int64 b){
  int64 r=a%b;
  while(r>0){
    a=b;b=r;r=a%b;
  }
  return b;
}

int64 calc(int64 n,int64 x){
  int64 g=gcd(n,x);
  return g*3*(n/g-1);
}

void run(void){
  int64 n,x;
  scanf("%lld%lld",&n,&x);
  printf("%lld\n",calc(n,x));
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:21:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lld",&n,&x);
   ^