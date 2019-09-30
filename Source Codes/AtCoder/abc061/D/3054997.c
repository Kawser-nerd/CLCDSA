#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

void run(void){
  int n,m;
  scanf("%d%d",&n,&m);
  int *vertex=(int *)malloc(sizeof(int)*m);
  int *next=(int *)malloc(sizeof(int)*m);
  int64 *cost=(int64 *)malloc(sizeof(int64)*m);
  int *start=(int *)malloc(sizeof(int)*n);
  int i;
  for(i=0;i<n;i++) start[i]=-1;
  for(i=0;i<m;i++){
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    a--;
    b--;
    vertex[i]=b;
    next[i]=start[a];
    start[a]=i;
    cost[i]=-c;
  }
  int64 *dp=(int64 *)malloc(sizeof(int64)*n);
  const int64 inf=1000000001LL*10000;
  for(i=0;i<n;i++) dp[i]=inf;
  dp[0]=0;
  for(i=0;i<n;i++){
    int j;
    for(j=0;j<n;j++){
      if(dp[j]==inf) continue;
      int p;
      for(p=start[j];p!=-1;p=next[p]){
	int v=vertex[p];
	dp[v]=MIN(dp[v],dp[j]+cost[p]);
      }
    }
  }
  int *flag=(int *)calloc(n,sizeof(int));
  for(i=0;i<n;i++){
    if(dp[i]==inf) continue;
    int p;
    for(p=start[i];p!=-1;p=next[p]){
      int v=vertex[p];
      if(dp[v]>dp[i]+cost[p]){
	flag[i]=1;
      }
    }
  }
  for(i=0;i<n;i++){
    int j;
    for(j=0;j<n;j++){
      if(dp[j]==inf) continue;
      if(flag[j]==0) continue;
      int p;
      for(p=start[j];p!=-1;p=next[p]){
	int v=vertex[p];
	flag[v]=1;
      }
    }
  }

  if(flag[n-1]){
    printf("inf\n");
  } else {
    printf("%lld\n",-dp[n-1]);
  }
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:13:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&m);
   ^
./Main.c:22:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d",&a,&b,&c);
     ^