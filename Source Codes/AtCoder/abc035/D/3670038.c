#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef long long int int64;
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

typedef struct pairingHeapNode{
  struct pairingHeapNode *next;
  struct pairingHeapNode *child;
  unsigned char val[];
} heapNode;

typedef struct pairingHeap{
  heapNode *root;
  int heapSize;
  size_t size;
  int (*cmp)(const void *,const void *);
} heap;

heapNode* newHeapNode(const void *v,const size_t size){
  heapNode *res=(heapNode *)malloc(sizeof(heapNode)+size);
  memcpy(res->val,v,size);
  res->next=NULL;
  res->child=NULL;
  return res;
}

void freeAllNode(heapNode *t){
  if(t==NULL) return;
  freeAllNode(t->next);
  freeAllNode(t->child);
  free(t);
  return;
}

heap* newHeap(const size_t size,int (*cmp)(const void *,const void *)){
  heap *res=(heap *)malloc(sizeof(heap));
  res->root=NULL;
  res->heapSize=0;
  res->size=size;
  res->cmp=cmp;
  return res;
}

void freeHeap(heap *h){
  freeAllNode(h->root);
  free(h);
  return;
}

int getSize(const heap *h){
  return h->heapSize;
}

int isEmpty(const heap *h){
  return getSize(h)==0;
}

heapNode* meld(heapNode *a,heapNode *b,int (*cmp)(const void *a,const void *b)){
  if(a==NULL) return b;
  if(b==NULL) return a;
  if(cmp(a->val,b->val)<=0){
    b->next=a->child;
    a->child=b;
    return a;
  } else {
    a->next=b->child;
    b->child=a;
    return b;
  }
}

void push(heap *h,const void *v){
  heapNode *p=newHeapNode(v,h->size);
  h->heapSize++;
  h->root=meld(h->root,p,h->cmp);
  return;
}

void pop(heap *h,void *v){
  memcpy(v,h->root->val,h->size);
  heapNode *lst=h->root->child;
  int (*cmp)(const void *a,const void *b)=h->cmp;
  free(h->root);
  h->heapSize--;
  heapNode *r=NULL;
  while(lst!=NULL && lst->next!=NULL){
    heapNode *a=lst;
    heapNode *b=lst->next;
    heapNode *next=lst->next->next;
    a->next=b->next=NULL;
    r=meld(r,meld(a,b,cmp),cmp);
    lst=next;
  }
  if(lst!=NULL) r=meld(r,lst,cmp);
  h->root=r;
  return;
}

void top(const heap *h,void *v){
  memcpy(v,h->root->val,h->size);
  return;
}

typedef struct indexNode{
  int v;
  int64 d;
} node;

int cmp(const void *a,const void *b){
  int64 p=((node *)a)->d;
  int64 q=((node *)b)->d;
  return p==q?0:p<q?-1:1;
}

int64* dijkstra(graph *g,int from){
  int64 *dp=(int64 *)calloc(g->v,sizeof(int64));
  int i;
  for(i=0;i<g->v;i++) dp[i]=(int64)100000*100000;
  dp[from]=0;
  int *used=(int *)calloc(g->v,sizeof(int));
  heap *h=newHeap(sizeof(node),cmp);
  push(h,&((node){from,0}));
  while(!isEmpty(h)){
    node t;
    pop(h,&t);
    if(used[t.v]) continue;
    const int v=t.v;
    used[v]=1;
    for(int p=g->start[v];p!=-1;p=g->next[p]){
      int u=g->vertex[p];
      int d=g->cost[p];
      if(dp[u]<=dp[v]+d) continue;
      dp[u]=dp[v]+d;
      push(h,&((node){u,dp[u]}));
    }
  }
  free(used);
  freeHeap(h);
  return dp;
}

void run(void){
  int n,m,t;
  scanf("%d%d%d",&n,&m,&t);
  int *a=(int *)calloc(n,sizeof(int));
  int i;
  for(i=0;i<n;i++) scanf("%d",a+i);
  graph *g=newGraph(n,m);
  graph *gr=newGraph(n,m);
  for(i=0;i<m;i++){
    int x,y,z;
    scanf("%d%d%d",&x,&y,&z);
    x--;y--;
    addEdge(g,x,y,z);
    addEdge(gr,y,x,z);
  }
  int64 *go=dijkstra(g,0);
  int64 *back=dijkstra(gr,0);
  int64 max=(int64)t*a[0];
  for(i=1;i<n;i++){
    if(t<go[i]+back[i]) continue;
    int64 local=(t-go[i]-back[i])*a[i];
    if(max<local) max=local;
  }
  printf("%lld\n",max);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:178:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d",&n,&m,&t);
   ^
./Main.c:181:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++) scanf("%d",a+i);
                    ^
./Main.c:186:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d",&x,&y,&z);
     ^