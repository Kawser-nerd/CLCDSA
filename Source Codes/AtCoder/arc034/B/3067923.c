#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

void run(void){
  int64 n;
  scanf("%lld",&n);
  int64 ans[100];
  int len=0;
  int64 x;
  for(x=MAX(1,n-18*9);x<n;x++){
    int64 y=x;
    int local=0;
    while(y>0){
      local+=y%10;
      y/=10;
    }
    if(x+local==n){
      ans[len++]=x;
    }
  }
  printf("%d\n",len);
  int i;
  for(i=0;i<len;i++) printf("%lld\n",ans[i]);

}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:13:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld",&n);
   ^