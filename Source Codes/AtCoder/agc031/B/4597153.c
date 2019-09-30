#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

void run(void){
  int n;
  scanf("%d",&n);
  const int m=200000;
  const int mod=1000000007;
  int *prev=(int *)calloc(m+1,sizeof(int));
  int i;
  int *dp=(int *)calloc(n+1,sizeof(int));
  dp[0]=1;
  for(i=1;i<=n;i++){
    int c;
    scanf("%d",&c);
    if(prev[c]==0 || prev[c]==i-1){
      dp[i]=dp[i-1];
    } else {
      dp[i]=(dp[i-1]+dp[prev[c]])%mod;
    }
    prev[c]=i;
  }
  printf("%d\n",dp[n]);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:13:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:22:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&c);
     ^