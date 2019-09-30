#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

void run(void){
  int n,p;
  scanf("%d%d",&n,&p);
  int cnt[2]={0,0};
  while(n--){
    int a;
    scanf("%d",&a);
    cnt[a&1]++;
  }
  int64 dp[2]={1,0};
  while(cnt[1]--){
    int64 x=dp[0];
    int64 y=dp[1];
    dp[0]=x+y;
    dp[1]=x+y;
  }
  printf("%lld\n",dp[p]<<cnt[0]);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:13:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&p);
   ^
./Main.c:17:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&a);
     ^