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

typedef struct node{
  int t;
  int c;
} node;

#define POS(rad,v) ((rad)*n+(v))

void run(void){
  int n,m;
  scanf("%d%d",&n,&m);
  graph *g=newGraph(n,2*m);
  while(m--){
    int a,b;
    scanf("%d%d",&a,&b);
    a--;b--;
    addEdge(g,a,b);
    addEdge(g,b,a);
  }
  const int f=10;
  node *dp=(node *)calloc(n*(f+1),sizeof(node));
  int i;
  for(i=0;i<(f+1)*n;i++) dp[i]=(node){0,0};
  int q;
  scanf("%d",&q);
  for(i=1;i<=q;i++){
    int v,d,c;
    scanf("%d%d%d",&v,&d,&c);
    v--;
    dp[POS(d,v)]=(node){i,c};
  }
  for(i=f;i>0;i--){
    for(int v=0;v<n;v++){
      if(dp[POS(i-1,v)].t<dp[POS(i,v)].t) dp[POS(i-1,v)]=dp[POS(i,v)];
      for(int p=g->start[v];p!=-1;p=g->next[p]){
	int u=g->vertex[p];
	if(dp[POS(i-1,u)].t<dp[POS(i,v)].t){
	  dp[POS(i-1,u)]=dp[POS(i,v)];
	}
      }
    }
  }
  for(i=0;i<n;i++){
    printf("%d\n",dp[POS(0,i)].c);
  }
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:50:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&m);
   ^
./Main.c:54:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&a,&b);
     ^
./Main.c:64:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&q);
   ^
./Main.c:67:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d",&v,&d,&c);
     ^