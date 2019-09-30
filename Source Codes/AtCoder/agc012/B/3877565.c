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

typedef struct splaNode{
  int v;
  int d;
  int c;
} node;

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
  node *s=(node *)calloc(q,sizeof(node));
  int i;
  for(i=0;i<q;i++){
    int v,d,c;
    scanf("%d%d%d",&v,&d,&c);
    s[i]=(node){v-1,d,c};
  }
  int *ans=(int *)calloc(n,sizeof(int));
  int *rad=(int *)calloc(n,sizeof(int));
  for(i=0;i<n;i++) rad[i]=-1;
  node *que=(node *)calloc(n,sizeof(node));
  for(i=q-1;i>=0;i--){
    if(rad[s[i].v]>=s[i].d) continue;
    rad[s[i].v]=s[i].d;
    int front=0;
    int last=0;
    que[last++]=s[i];
    while(front<last){
      const node t=que[front++];
      if(ans[t.v]==0) ans[t.v]=t.c;
      if(t.d==0) continue;
      for(int p=g->start[t.v];p!=-1;p=g->next[p]){
	int u=g->vertex[p];
	if(rad[u]>=t.d-1) continue;
	rad[u]=t.d-1;
	que[last++]=(node){u,t.d-1,t.c};
      }
    }
  }
  for(i=0;i<n;i++) printf("%d\n",ans[i]);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:49:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&m);
   ^
./Main.c:53:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&a,&b);
     ^
./Main.c:59:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&q);
   ^
./Main.c:64:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d",&v,&d,&c);
     ^