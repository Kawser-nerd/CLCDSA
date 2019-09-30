#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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

typedef struct binaryHeap{
  void *h;
  size_t heapSize;
  size_t maxSize;
  size_t size;
  int (*cmp)(const void *,const void *);
} heap;

heap* newHeap(const size_t size,int (*cmpF)(const void *,const void *)){
  const size_t maxSize=1;
  heap *res=(heap *)malloc(sizeof(heap));
  res->h=malloc(size*(maxSize+1));
  res->heapSize=0;
  res->maxSize=maxSize;
  res->size=size;
  res->cmp=cmpF;
  return res;
}

int isEmpty(const heap *h){
  return h->heapSize==0;
}

void freeHeap(heap *h){
  free(h->h);
  free(h);
  return;
}

void initHeap(heap *h){
  h->heapSize=0;
  return;
}

static inline void heapFunc_swap(void * restrict a,void * restrict b,void * restrict tmp,size_t size){
  memcpy(tmp,a,size);
  memcpy(a,b,size);
  memcpy(b,tmp,size);
  return;
}

void push(heap *q,const void *p){
  if(q->heapSize==q->maxSize){
    q->maxSize*=2;
    q->h=realloc(q->h,q->size*(q->maxSize+1));
  }
  q->heapSize+=1;
  char *h=(char *)(q->h);
  int k=q->heapSize;
  const size_t size=q->size;
  int (*cmp)(const void *,const void *)=q->cmp;
  memcpy(h+k*size,p,size);
  while(k>1){
    size_t parent=k/2;
    if(cmp(h+parent*size,h+k*size)<=0) return;
    heapFunc_swap(h+parent*size,h+k*size,h,size);
    k=parent;
  }
  return;
}

void pop(heap *q,void *res){
  char *h=(char *)(q->h);
  const size_t size=q->size;
  if(res!=NULL) memcpy(res,h+size,size);
  memcpy(h+size,h+size*q->heapSize,size);
  q->heapSize-=1;
  int (*cmp)(const void *,const void *)=q->cmp;
  const size_t n=q->heapSize;
  size_t k=1;
  while(2*k+1<=n){
    size_t next=cmp(h+2*k*size,h+(2*k+1)*size)<=0?2*k:2*k+1;
    if(cmp(h+k*size,h+next*size)<=0) return;
    heapFunc_swap(h+k*size,h+next*size,h,size);
    k=next;
  }
  if(2*k<=n && cmp(h+k*size,h+2*k*size)>0) heapFunc_swap(h+k*size,h+2*k*size,h,size);
  return;
}

void top(const heap *q,void *res){
  memcpy(res,(char *)q->h+q->size,q->size);
  return;
}

typedef struct node{
  int index;
  int val;
} node;

int cmp(const void *a,const void *b){
  return ((node *)a)->val-((node *)b)->val;
}

void run(void){
  int n,m;
  scanf("%d%d",&n,&m);
  graph *g=newGraph(n,2*m);
  graph *f=newGraph(n,2*m);
  while(m--){
    int c,a,b;
    scanf("%d%d%d",&c,&a,&b);
    if(c==0){
      addEdge(g,a,b);
      addEdge(g,b,a);
    } else {
      addEdge(f,a,b);
      addEdge(f,b,a);
    }
  }
  int *now=(int *)calloc(n,sizeof(int));
  int *next=(int *)calloc(n,sizeof(int));
  int *used=(int *)calloc(n,sizeof(int));
  int *stack=(int *)calloc(n,sizeof(int));
  int i;
  for(i=0;i<n;i++) now[i]=n*n;
  now[0]=0;
  memcpy(next,now,sizeof(int)*n);
  heap *h=newHeap(sizeof(node),cmp);
  push(h,&((node){0,0}));
  int k=0;
  while(!isEmpty(h)){
    memset(used,0,sizeof(int)*n);
    int top=0;
    while(!isEmpty(h)){
      node t;
      pop(h,&t);
      const int v=t.index;
      if(used[v]) continue;
      used[v]=1;
      stack[top++]=v;
      for(int p=g->start[v];p!=-1;p=g->next[p]){
	const int u=g->vertex[p];
	if(now[u]<=now[v]+1) continue;
	next[u]=now[u]=now[v]+1;
	push(h,&((node){u,now[u]}));
      }
    }
    for(i=0;i<top;i++){
      const int v=stack[i];
      for(int p=f->start[v];p!=-1;p=f->next[p]){
	const int u=f->vertex[p];
	if(next[u]<=now[v]+k+1) continue;
	next[u]=now[v]+k+1;
	push(h,&((node){u,next[u]}));
      }
    }
    for(i=0;i<top;i++){
      const int v=stack[i];
      for(int p=f->start[v];p!=-1;p=f->next[p]){
	const int u=f->vertex[p];
	now[u]=next[u];
      }
    }
    k++;
  }
  for(i=0;i<n;i++) printf("%d\n",now[i]);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:138:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&m);
   ^
./Main.c:143:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d",&c,&a,&b);
     ^