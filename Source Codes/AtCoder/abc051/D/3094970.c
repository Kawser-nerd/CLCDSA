#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

#define POS(i,j) ((i)*n+(j))

void run(void){
  int n,m;
  scanf("%d%d",&n,&m);
  const int inf=100000+1;
  int cost[10000];
  int i,j,k;
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      cost[POS(i,j)]=i==j?0:inf;
    }
  }
  for(i=0;i<m;i++){
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    a--;b--;
    cost[POS(a,b)]=c;
    cost[POS(b,a)]=c;
  }
  int dp[10000];
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      dp[POS(i,j)]=cost[POS(i,j)];
    }
  }
  for(k=0;k<n;k++){
    for(i=0;i<n;i++){
      for(j=0;j<n;j++){
	if(dp[POS(i,j)]>dp[POS(i,k)]+dp[POS(k,j)]) dp[POS(i,j)]=dp[POS(i,k)]+dp[POS(k,j)];
      }
    }
  }
  int cnt=0;
  for(i=0;i<n;i++){
    for(j=i+1;j<n;j++){
      if(cost[POS(i,j)]!=inf && dp[POS(i,j)]<cost[POS(i,j)]) cnt++;
    }
  }
  printf("%d\n",cnt);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:15:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&m);
   ^
./Main.c:26:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d",&a,&b,&c);
     ^