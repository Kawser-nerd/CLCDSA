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

#define MAX(a,b) ((a)>(b)?(a):(b))

void run(void){
  int n;
  scanf("%d",&n);
  graph *g=newGraph(n,n);
  int *parent=(int *)calloc(n,sizeof(int));
  int i;
  for(i=1;i<n;i++){
    scanf("%d",parent+i);
    addEdge(g,parent[i],i);
  }
  int *dp=(int *)calloc(n,sizeof(int));
  for(i=n-1;i>=0;i--){
    int s=1;
    for(int p=g->start[i];p!=-1;p=g->next[p]){
      int u=g->vertex[p];
      s+=dp[u];
    }
    dp[i]=s;
  }
  for(i=0;i<n;i++){
    int max=n-dp[i];
    for(int p=g->start[i];p!=-1;p=g->next[p]){
      int u=g->vertex[p];
      max=MAX(max,dp[u]);
    }
    printf("%d\n",max);
  }
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:45:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:50:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",parent+i);
     ^