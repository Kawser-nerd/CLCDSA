#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

void dfs(int from,int *vertex,int *cost,int *next,int *start,int64 *dp,int *stack,int n){
  int i;
  for(i=0;i<n;i++) dp[i]=-1;
  dp[from]=0;
  stack[0]=from;
  int top=1;
  while(top>0){
    int v=stack[--top];
    int p;
    for(p=start[v];p!=-1;p=next[p]){
      int u=vertex[p];
      if(dp[u]==-1){
	dp[u]=dp[v]+cost[p];
	stack[top++]=u;
      }
    }
  }
  return;
}

void add(int a,int b,int c,int *v,int *cost,int *next,int *start,int p){
  v[p]=b;
  cost[p]=c;
  next[p]=start[a];
  start[a]=p;
  return;
}

void run(void){
  int n;
  scanf("%d",&n);
  int *vertex=(int *)malloc(sizeof(int)*2*(n-1));
  int *cost=(int *)malloc(sizeof(int)*2*(n-1));
  int *next=(int *)malloc(sizeof(int)*2*(n-1));
  int *start=(int *)malloc(sizeof(int)*n);
  int i;
  for(i=0;i<n;i++) start[i]=-1;
  for(i=0;i<n-1;i++){
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    a--;b--;
    add(a,b,c,vertex,cost,next,start,2*i);
    add(b,a,c,vertex,cost,next,start,2*i+1);
  }
  int q,k;
  scanf("%d%d",&q,&k);
  k--;
  int64 *dp=(int64 *)malloc(sizeof(int64)*n);
  int *stack=(int *)malloc(sizeof(int)*n);
  dfs(k,vertex,cost,next,start,dp,stack,n);
  while(q--){
    int x,y;
    scanf("%d%d",&x,&y);
    x--;y--;
    printf("%lld\n",dp[x]+dp[y]);
  }
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:41:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:50:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d",&a,&b,&c);
     ^
./Main.c:56:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&q,&k);
   ^
./Main.c:63:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&x,&y);
     ^