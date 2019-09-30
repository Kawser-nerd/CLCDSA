#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

void run(void){
  int k;
  scanf("%d",&k);
  int64 a,b;
  a=2;
  b=1;
  int i;
  for(i=1;i<k;i++){
    int64 c=a+b;
    b=a;
    a=c;
  }
  printf("%lld %lld\n",a,b);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:13:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&k);
   ^