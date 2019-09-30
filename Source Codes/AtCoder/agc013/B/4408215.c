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

void run(void){
  int n,m;
  scanf("%d%d",&n,&m);
  graph *g=newGraph(n,2*m);
  for(int i=0;i<m;i++){
    int a,b;
    scanf("%d%d",&a,&b);
    a--; b--;
    addEdge(g,a,b);
    addEdge(g,b,a);
  }
  int *ans=(int *)calloc(2*n,sizeof(int));
  ans[n]=0;
  int *used=(int *)calloc(n,sizeof(int));
  used[0]=1;
  int l=n;
  int r=n;
  while(1){
    int ok=1;
    for(int p=g->start[ans[r]];p!=-1;p=g->next[p]){
      int u=g->vertex[p];
      if(!used[u]){
	ok=0;
	used[u]=1;
	ans[++r]=u;
	break;
      }
    }
    if(ok) break;
  }
  while(1){
    int ok=1;
    for(int p=g->start[ans[l]];p!=-1;p=g->next[p]){
      int u=g->vertex[p];
      if(!used[u]){
	ok=0;
	used[u]=1;
	ans[--l]=u;
	break;
      }
    }
    if(ok) break;
  }
  printf("%d\n",r-l+1);
  for(int i=l;i<=r;i++) printf("%d ",ans[i]+1);
  puts("");
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:43:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&m);
   ^
./Main.c:47:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&a,&b);
     ^