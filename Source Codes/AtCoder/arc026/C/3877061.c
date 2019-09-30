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

typedef struct keikoutou{
  int l,r,c;
} range;

int cmpL(const void *a,const void *b){
  return ((range *)a)->l-((range *)b)->l;
}

typedef struct{
  int r;
  int64 cost;
} node;

int cmpNode(const void *a,const void *b){
  int64 p=((node *)a)->cost;
  int64 q=((node *)b)->cost;
  return p==q?0:p<q?-1:1;
}

void run(void){
  int n,len;
  scanf("%d%d",&n,&len);
  range *a=(range *)calloc(n,sizeof(range));
  int i;
  for(i=0;i<n;i++){
    int l,r,c;
    scanf("%d%d%d",&l,&r,&c);
    a[i]=(range){l,r,c};
  }
  qsort(a,n,sizeof(range),cmpL);
  heap *h=newHeap(sizeof(node),cmpNode);
  push(h,&((node){0,0}));
  for(i=0;i<n;i++){
    node t;
    top(h,&t);
    while(t.r<a[i].l){
      pop(h,NULL);
      top(h,&t);
    }
    if(t.r>=a[i].r) continue;
    push(h,&((node){a[i].r,t.cost+a[i].c}));
  }
  node t;
  pop(h,&t);
  while(t.r<len) pop(h,&t);
  printf("%lld\n",t.cost);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:113:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&len);
   ^
./Main.c:118:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d",&l,&r,&c);
     ^