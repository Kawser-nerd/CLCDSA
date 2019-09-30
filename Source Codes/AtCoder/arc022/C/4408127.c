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

int bfs(graph *g,int src){
  int n=g->v;
  int *q=(int *)calloc(n,sizeof(int));
  int *used=(int *)calloc(n,sizeof(int));
  int front=0,last=0;
  q[last++]=src;
  used[src]=1;
  while(last<n){
    int v=q[front++];
    for(int p=g->start[v];p!=-1;p=g->next[p]){
      int u=g->vertex[p];
      if(used[u]) continue;
      q[last++]=u;
      used[u]=1;
    }
  }
  int res=q[n-1];
  free(q);
  free(used);
  return res;
}

void run(void){
  int n;
  scanf("%d",&n);
  graph *g=newGraph(n,2*n);
  int i;
  for(i=1;i<n;i++){
    int a,b;
    scanf("%d%d",&a,&b);
    a--;b--;
    addEdge(g,a,b);
    addEdge(g,b,a);
  }
  int v=bfs(g,0);
  int u=bfs(g,v);
  printf("%d %d\n",v+1,u+1);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:65:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:70:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&a,&b);
     ^