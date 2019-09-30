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
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

int cmp(const void *a,const void *b){
  return *(int *)a-*(int *)b;
}

void run(void){
  int n;
  scanf("%d",&n);
  graph *g=newGraph(n,n);
  int i;
  for(i=1;i<n;i++){
    int a;
    scanf("%d",&a);
    addEdge(g,a-1,i);
  }
  int *q=(int *)calloc(n,sizeof(int));
  int front=0,last=0;
  q[last++]=0;
  while(last<n){
    int v=q[front++];
    for(int p=g->start[v];p!=-1;p=g->next[p]){
      int u=g->vertex[p];
      q[last++]=u;
    }
  }
  int *dp=(int *)calloc(n,sizeof(int));
  int *array=(int *)calloc(n,sizeof(int));
  for(i=n-1;i>=0;i--){
    int v=q[i];
    int len=0;
    for(int p=g->start[v];p!=-1;p=g->next[p]){
      int u=g->vertex[p];
      array[len++]=dp[u];
    }
    qsort(array,len,sizeof(int),cmp);
    int d=0;
    for(int j=0;j<len;j++){
      d=MAX(d,array[len-1-j]+1+j);
    }
    dp[v]=d;
  }
  printf("%d\n",dp[0]);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:51:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:56:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&a);
     ^