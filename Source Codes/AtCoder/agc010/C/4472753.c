#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef struct directedGraph{
  int *vertex;
  int *next;
  int *start;
  int v,e;
  int pointer;
} graph;

graph* newGraph(const int v,const int e){
  graph *g=(graph *)malloc(sizeof(graph));
  g->vertex=(int *)calloc(e,sizeof(int));
  g->next=(int *)calloc(e,sizeof(int));
  g->start=(int *)calloc(v,sizeof(int));
  for(int i=0;i<v;i++) g->start[i]=-1;
  g->v=v;
  g->e=e;
  g->pointer=0;
  return g;
}

void freeGraph(graph *g){
  free(g->vertex);
  free(g->next);
  free(g->start);
  free(g);
  return;
}

void addEdge(graph *g,const int from,const int to){
  const int p=g->pointer;
  g->vertex[p]=to;
  g->next[p]=g->start[from];
  g->start[from]=p;
  g->pointer++;
  return;
}

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

void run(void){
  int n;
  scanf("%d",&n);
  int *a=(int *)calloc(n,sizeof(int));
  int i;
  for(i=0;i<n;i++) scanf("%d",a+i);
  graph *g=newGraph(n+1,2*n);
  for(i=1;i<n;i++){
    int v,u;
    scanf("%d%d",&v,&u);
    v--;u--;
    addEdge(g,v,u);
    addEdge(g,u,v);
  }
  int *q=(int *)calloc(n,sizeof(int));
  int *parent=(int *)calloc(n,sizeof(int));
  int front=0,last=0;
  q[last++]=0;
  while(last<n){
    int v=q[front++];
    for(int p=g->start[v];p!=-1;p=g->next[p]){
      int u=g->vertex[p];
      if(u==parent[v]) continue;
      parent[u]=v;
      q[last++]=u;
    }
  }
  int *dp=(int *)calloc(n+1,sizeof(int));
  for(i=n-1;i>=0;i--){
    int v=q[i];
    int max=0;
    int64 sum=0;
    int d=0;
    for(int p=g->start[v];p!=-1;p=g->next[p]){
      int u=g->vertex[p];
      if(u==parent[v]) continue;
      d++;
      sum+=dp[u];
      max=MAX(dp[u],max);
    }
    if(d==0){
      dp[v]=a[v];
      continue;
    }
    if(d==1){
      if(sum!=a[v]){
	puts("NO");
	return;
      }
      dp[v]=sum;
      continue;
    }
    if(2*a[v]<sum || a[v]>sum){
      puts("NO");
      return;
    }
    int t=2*a[v]-sum;
    int l=(sum-t)/2;
    if(l>MIN(sum/2,sum-max)){
      puts("NO");
      return;
    }
    dp[v]=t;
  }
  int d=0;
  for(i=1;i<n;i++) if(parent[i]==0) d++;
  if(d==1 || dp[0]==0){
    puts("YES");
  } else {
    puts("NO");
  }
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:50:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:53:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++) scanf("%d",a+i);
                    ^
./Main.c:57:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&v,&u);
     ^