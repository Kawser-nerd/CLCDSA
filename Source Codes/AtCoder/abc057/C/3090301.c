#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

int digit(int64 n){
  int res=0;
  while(n>0){
    res++;
    n/=10;
  }
  return res;
}

void run(void){
  int64 n;
  scanf("%lld",&n);
  int min=digit(n);
  int i;
  for(i=1;(int64)i*i<=n;i++){
    if(n%i!=0) continue;
    int64 a=i;
    int64 b=n/i;
    min=MIN(min,MAX(digit(a),digit(b)));
  }
  printf("%d\n",min);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:22:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld",&n);
   ^