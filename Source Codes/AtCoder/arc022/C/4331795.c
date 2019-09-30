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

void bfs(int s,graph *g,int *q,int n){
  int *used=(int *)calloc(n,sizeof(int));
  int front=0,last=0;
  q[last++]=s;
  used[s]=1;
  while(last<n){
    int v=q[front++];
    for(int p=g->start[v];p!=-1;p=g->next[p]){
      int u=g->vertex[p];
      if(used[u]) continue;
      q[last++]=u;
      used[u]=1;
    }
  }
  free(used);
}

void run(void){
  int n;
  scanf("%d",&n);
  graph *g=newGraph(n,2*n);
  int i;
  for(i=0;i<n-1;i++){
    int a,b;
    scanf("%d%d",&a,&b);
    a--;b--;
    addEdge(g,a,b);
    addEdge(g,b,a);
  }
  int *q=(int *)calloc(n,sizeof(int));
  bfs(0,g,q,n);
  int s=q[n-1];
  bfs(s,g,q,n);
  int t=q[n-1];
  printf("%d %d\n",s+1,t+1);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:60:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:65:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&a,&b);
     ^