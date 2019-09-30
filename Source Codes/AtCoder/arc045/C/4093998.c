#include<stdio.h>
#include<stdlib.h>

typedef int EdgeWeight;

typedef struct directedGraph{
  int *vertex;
  EdgeWeight *cost;
  int *next;
  int *start;
  int v,e;
  int pointer;
} graph;

graph* newGraph(const int v,const int e){
  graph *g=(graph *)malloc(sizeof(graph));
  g->vertex=(int *)calloc(e,sizeof(int));
  g->cost=(EdgeWeight *)calloc(e,sizeof(EdgeWeight));
  g->next=(int *)calloc(e,sizeof(int));
  g->start=(int *)calloc(v,sizeof(int));
  for(int i=0;i<v;i++) g->start[i]=-1;
  g->v=v;
  g->e=e;
  g->pointer=0;
  return g;
}

void addEdge(graph *g,const int from,const int to,const EdgeWeight cost){
  const int p=g->pointer;
  g->vertex[p]=to;
  g->cost[p]=cost;
  g->next[p]=g->start[from];
  g->start[from]=p;
  g->pointer++;
  return;
}

typedef long long int int64;

int cmp(const void *a,const void *b){
  return *(int *)a-*(int *)b;
}

int search(int v,int *a,int n){
  int l=0;
  int r=n;
  while(r-l>1){
    int m=(l+r)/2;
    if(v<=a[m]){
      r=m;
    } else {
      l=m;
    }
  }
  return l;
}

void run(void){
  int n,x;
  scanf("%d%d",&n,&x);
  graph *g=newGraph(n,2*n);
  int i;
  for(i=0;i<n-1;i++){
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    a--;b--;
    addEdge(g,a,b,c);
    addEdge(g,b,a,c);
  }
  int *parent=(int *)calloc(n,sizeof(int));
  int *q=(int *)calloc(n,sizeof(int));
  int *dp=(int *)calloc(n,sizeof(int));
  int front=0,last=0;
  q[last++]=0;
  while(last<n){
    const int v=q[front++];
    for(int p=g->start[v];p!=-1;p=g->next[p]){
      const int u=g->vertex[p];
      if(u==parent[v]) continue;
      parent[u]=v;
      dp[u]=dp[v]^g->cost[p];
      q[last++]=u;
    }
  }
  qsort(dp,n,sizeof(int),cmp);
  int64 ans=0;
  i=0;
  while(i<n){
    int c=dp[i];
    int j=i;
    while(j<n && dp[j]==c) j++;
    if((x^c)==c){
      ans+=(int64)(j-i-1)*(j-i)/2;
    } else if((x^c)>c){
      ans+=(int64)(j-i)*(search((x^c)+1,dp,n)-search(x^c,dp,n));
    }
    i=j;
  }
  printf("%lld\n",ans);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:60:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&x);
   ^
./Main.c:65:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d",&a,&b,&c);
     ^