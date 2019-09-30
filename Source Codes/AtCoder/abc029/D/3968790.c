#include<stdio.h>

int calc(int n){
  int digit[9];
  int len=0;
  while(n>0){
    digit[len++]=n%10;
    n/=10;
  }
  int dp[2][10];
  int i,j;
  for(i=0;i<10;i++) dp[0][i]=0;
  int sup=0;
  int now=0;
  for(i=0;i<len;i++){
    const int d=digit[len-1-i];
    const int next=now^1;
    dp[next][0]=9*dp[now][0];
    int j;
    for(j=1;j<10;j++){
      dp[next][j]=dp[now][j-1]+9*dp[now][j];
    }
    for(j=0;j<d;j++){
      if(j==1){
	dp[next][sup+1]++;
      } else {
	dp[next][sup]++;
      }
    }
    if(d==1) sup++;
    now=next;
  }
  int cnt=0;
  for(j=0;j<10;j++){
    cnt+=dp[now][j]*j;
  }
  return cnt+sup;
}

void run(void){
  int n;
  scanf("%d",&n);
  printf("%d\n",calc(n));
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:42:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^