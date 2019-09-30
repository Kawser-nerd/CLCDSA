#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

void run(void){
  int a,b,k,l;
  scanf("%d%d%d%d",&a,&b,&k,&l);
  int64 y=(int64)k/l*b;
  int64 x=MIN((int64)a*(k%l),b);
  printf("%lld\n",x+y);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:13:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d%d",&a,&b,&k,&l);
   ^