#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

void run(void){
  int64 q,h,s,d;
  scanf("%lld%lld%lld%lld",&q,&h,&s,&d);
  int64 n;
  scanf("%lld",&n);
  int64 t=MIN(4*q,MIN(2*h,s));
  int64 min=MIN(n*t,(n/2)*d+(n%2)*t);
  printf("%lld\n",min);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:13:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lld%lld%lld",&q,&h,&s,&d);
   ^
./Main.c:15:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld",&n);
   ^