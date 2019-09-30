#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

typedef struct edge{
  int a,b;
} edge;

int calcDepth(int v,edge *e,int n){
  int res=0;
  for(int i=0;i<n-1;i++){
    if(e[i].a!=v && e[i].b!=v) continue;
    const edge t=e[i];
    e[i]=(edge){-1,-1};
    int k=calcDepth(t.a^t.b^v,e,n)+1;
    res=MAX(res,k);
    e[i]=t;
  }
  return res;
}

void calcLeaf(int v,edge *e,int n,int *dp){
  int cnt=0;
  for(int i=0;i<n-1;i++){
    if(e[i].a!=v && e[i].b!=v) continue;
    cnt++;
    const edge t=e[i];
    e[i]=(edge){-1,-1};
    calcLeaf(t.a^t.b^v,e,n,dp+1);
    e[i]=t;
  }
  dp[0]=MAX(dp[0],cnt);
}

void run(void){
  int n;
  scanf("%d",&n);
  edge *e=(edge *)calloc(n-1,sizeof(edge));
  int i;
  for(i=1;i<n;i++){
    int a,b;
    scanf("%d%d",&a,&b);
    e[i-1]=(edge){a-1,b-1};
  }
  int min=n;
  for(i=0;i<n;i++){
    int d=calcDepth(i,e,n);
    min=MIN(min,d);
  }
  for(i=0;i<n-1;i++){
    const edge t=e[i];
    e[i]=(edge){-1,-1};
    int a=calcDepth(t.a,e,n);
    int b=calcDepth(t.b,e,n);
    e[i]=t;
    min=MIN(min,MAX(a,b));
  }
  const int depth=min;
  int *dp=(int *)calloc(depth,sizeof(int));
  int64 ans=1000000000000000000LL;
  for(i=0;i<n;i++){
    int d=calcDepth(i,e,n);
    if(d!=depth) continue;
    memset(dp,0,sizeof(int)*depth);
    calcLeaf(i,e,n,dp);
    int64 local=1;
    for(int j=0;j<depth;j++) local*=dp[j];
    ans=MIN(ans,local);
  }
  for(i=0;i<n-1;i++){
    const edge t=e[i];
    e[i]=(edge){-1,-1};
    int a=calcDepth(t.a,e,n);
    int b=calcDepth(t.b,e,n);
    e[i]=t;
    if(MAX(a,b)!=depth) continue;
    e[i]=(edge){-1,-1};
    memset(dp,0,sizeof(int)*depth);
    calcLeaf(t.a,e,n,dp);
    calcLeaf(t.b,e,n,dp);
    e[i]=t;
    int64 local=2;
    for(int j=0;j<depth;j++) local*=dp[j];
    ans=MIN(ans,local);
  }
  printf("%d %lld\n",depth+1,ans);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:43:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:48:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&a,&b);
     ^