#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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

typedef long long int int64;

typedef struct edge{
  int a,b;
  int c;
} edge;

typedef struct indexNode{
  int index;
  int val;
} node;

int cmpNode(const void *a,const void *b){
  return ((node *)a)->val-((node *)b)->val;
}

int cmpEdge(const void *a,const void *b){
  return ((edge *)a)->c-((edge *)b)->c;
}

int root(int *u,int x){
  if(u[x]==x) return x;
  return u[x]=root(u,u[x]);
}

int same(int *u,int x,int y){
  return root(u,x)==root(u,y);
}

void unite(int *u,int x,int y){
  x=root(u,x);
  y=root(u,y);
  if(x==y) return;
  u[x]=y;
}

void run(void){
  int n;
  scanf("%d",&n);
  node *x=(node *)calloc(n,sizeof(node));
  node *y=(node *)calloc(n,sizeof(node));
  int i;
  for(i=0;i<n;i++){
    int a,b;
    scanf("%d%d",&a,&b);
    x[i]=(node){i,a};
    y[i]=(node){i,b};
  }
  qsort(x,n,sizeof(node),cmpNode);
  qsort(y,n,sizeof(node),cmpNode);
  heap *h=newHeap(sizeof(edge),cmpEdge);
  for(i=0;i<n-1;i++){
    push(h,&((edge){x[i].index,x[i+1].index,x[i+1].val-x[i].val}));
    push(h,&((edge){y[i].index,y[i+1].index,y[i+1].val-y[i].val}));
  }
  int cnt=0;
  int *u=(int *)calloc(n,sizeof(int));
  for(i=0;i<n;i++) u[i]=i;
  int64 ans=0;
  for(i=0;cnt<n-1;i++){
    edge e;
    pop(h,&e);
    if(same(u,e.a,e.b)) continue;
    unite(u,e.a,e.b);
    ans+=e.c;
    cnt++;
  }
  printf("%lld\n",ans);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:128:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:134:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&a,&b);
     ^