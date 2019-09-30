#include<stdio.h>

typedef long long int int64;

#define ABS(a) ((a)>(0)?(a):-(a))

void run(void){
  int64 x,y;
  scanf("%lld%lld",&x,&y);
  puts(ABS(x-y)>1?"Alice":"Brown");
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lld",&x,&y);
   ^