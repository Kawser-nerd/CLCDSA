#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

int digitSum(int64 n){
  int sum=0;
  while(n>0){
    sum+=n%10;
    n/=10;
  }
  return sum;
}

void run(void){
  int64 n;
  scanf("%lld",&n);
  int t=digitSum(n);
  int64 d=1;
  while(10*d<n) d*=10;
  int s=digitSum((n/d-1)*d+d-1);
  printf("%d\n",MAX(s,t));
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:22:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld",&n);
   ^