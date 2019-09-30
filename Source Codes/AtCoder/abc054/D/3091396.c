#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

#define POS(i,j) ((i)*(l+1)+(j))

void run(void){
  int n,ma,mb;
  scanf("%d%d%d",&n,&ma,&mb);
  int l=400;
  int *dp=(int *)malloc(sizeof(int)*(l+1)*(l+1));
  const int inf=1000000;
  int i,j;
  for(i=0;i<=l;i++) for(j=0;j<=l;j++) dp[POS(i,j)]=inf;
  dp[POS(0,0)]=0;
  while(n--){
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    for(i=l;i>=a;i--){
      for(j=l;j>=b;j--){
	if(dp[POS(i-a,j-b)]==inf) continue;
	dp[POS(i,j)]=MIN(dp[POS(i,j)],dp[POS(i-a,j-b)]+c);
      }
    }
  }
  int min=-1;
  for(i=1;i*ma<=l && i*mb<=l;i++){
    if(dp[POS(i*ma,i*mb)]==inf) continue;
    min=(min==-1?dp[POS(i*ma,i*mb)]:MIN(min,dp[POS(i*ma,i*mb)]));
  }
  printf("%d\n",min);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:15:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d",&n,&ma,&mb);
   ^
./Main.c:24:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d",&a,&b,&c);
     ^