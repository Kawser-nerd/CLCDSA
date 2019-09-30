#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

int digitSum(int n){
  int res=0;
  while(n>0){
    res+=n%10;
    n/=10;
  }
  return res;
}

void run(void){
  int n;
  scanf("%d",&n);
  int min=n;
  int i;
  for(i=1;i<n;i++){
    min=MIN(min,digitSum(i)+digitSum(n-i));
  }
  printf("%d\n",min);
  return;
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:22:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^