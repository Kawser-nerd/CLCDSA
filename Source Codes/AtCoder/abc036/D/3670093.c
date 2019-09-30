#include<stdio.h>
#include<stdlib.h>

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

void addEdge(graph *g,const int from,const int to){
  const int p=g->pointer;
  g->vertex[p]=to;
  g->next[p]=g->start[from];
  g->start[from]=p;
  g->pointer++;
  return;
}

typedef long long int int64;

const int mod=1000000007;
int n;
graph *g;
int *dp;
int *used;

#define POS(i,j) ((i)*n+(j))

int calc(int c,int v){
  if(dp[POS(c,v)]!=-1) return dp[POS(c,v)];
  used[v]=1;
  if(c==0){//white
    int local=1;
    for(int p=g->start[v];p!=-1;p=g->next[p]){
      int u=g->vertex[p];
      if(!used[u]) local=(int64)local*(calc(0,u)+calc(1,u))%mod;
    }
    dp[POS(c,v)]=local;
  } else {
    int local=1;
    for(int p=g->start[v];p!=-1;p=g->next[p]){
      int u=g->vertex[p];
      if(!used[u]) local=(int64)local*calc(0,u)%mod;
    }
    dp[POS(c,v)]=local;
  }
  used[v]=0;
  return dp[POS(c,v)];
}

void run(void){
  scanf("%d",&n);
  g=newGraph(n,2*(n-1));
  int i;
  for(i=0;i<n-1;i++){
    int a,b;
    scanf("%d%d",&a,&b);
    a--;b--;
    addEdge(g,a,b);
    addEdge(g,b,a);
  }
  dp=(int *)calloc(2*n,sizeof(int));
  used=(int *)calloc(n,sizeof(int));
  for(i=0;i<2*n;i++) dp[i]=-1;
  int ans=(calc(0,0)+calc(1,0))%mod;
  printf("%d\n",ans);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:66:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:71:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&a,&b);
     ^