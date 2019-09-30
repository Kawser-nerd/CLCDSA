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

node calc(node a,node b){
  return a.t>b.t?a:b;
}

#define POS(i,j) ((i)*n+(j))

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
  int q;
  scanf("%d",&q);
  node *dp=(node *)calloc(n*11,sizeof(node));
  int i,j;
  for(i=1;i<=q;i++){
    int v,d,c;
    scanf("%d%d%d",&v,&d,&c);
    v--;
    dp[POS(d,v)]=(node){i,c};
  }
  for(i=10;i>0;i--){
    for(j=0;j<n;j++){
      if(dp[POS(i,j)].c==0) continue;
      for(int p=g->start[j];p!=-1;p=g->next[p]){
	int u=g->vertex[p];
	dp[POS(i-1,u)]=calc(dp[POS(i-1,u)],dp[POS(i,j)]);
      }
    }
  }
  for(i=0;i<n;i++){
    node t={0,0};
    for(j=0;j<=10;j++){
      t=calc(t,dp[POS(j,i)]);
    }
    printf("%d\n",t.c);
  }
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:54:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&m);
   ^
./Main.c:58:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&a,&b);
     ^
./Main.c:64:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&q);
   ^
./Main.c:69:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d",&v,&d,&c);
     ^