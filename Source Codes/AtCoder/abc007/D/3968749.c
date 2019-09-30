#include<stdio.h>

typedef long long int int64;

int64 calc(int64 n){
  if(n<=3) return 0;
  int digit[19];
  int len=0;
  while(n>0){
    digit[len++]=n%10;
    n/=10;
  }
  int64 dp[2][2];
  dp[0][0]=dp[0][1]=0;
  int sup=0;
  int now=0;
  while(len--){
    const int d=digit[len];
    const int next=now^1;
    dp[next][0]=dp[now][0]*8;
    dp[next][1]=10*dp[now][1]+2*dp[now][0];
    for(int i=0;i<d;i++){
      if(i==4 || i==9){
	dp[next][1]++;
      } else {
	dp[next][sup]++;
      }
    }
    sup|=(d==4||d==9?1:0);
    now=next;
  }
  dp[now][sup]++;
  return dp[now][1];
}

void run(void){
  int64 a,b;
  scanf("%lld%lld",&a,&b);
  int64 ans=calc(b)-calc(a-1);
  printf("%lld\n",ans);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:38:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lld",&a,&b);
   ^