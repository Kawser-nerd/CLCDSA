#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct indexNode{
  int val;
  int index;
} node;

node calcMin(node a,node b){
  return a.val<b.val?a:b;
}

const node inf={400000,0};

typedef struct RMQ{
  node *a;
  int size;
} seg;

seg* newRMQ(const int n){
  int k=1;
  while(k<n) k*=2;
  seg *res=(seg *)calloc(1,sizeof(seg));
  res->a=(node *)calloc(2*k,sizeof(node));
  res->size=k;
  for(int i=1;i<2*k;i++) res->a[i]=inf;
  return res;
}

void update(seg *s,int index,node v){
  int x=index+s->size;
  s->a[x]=v;
  x/=2;
  while(x>=1){
    s->a[x]=calcMin(s->a[2*x],s->a[2*x+1]);
    x>>=1;
  }
}

node query(seg *s,int l,int r){
  node res=inf;
  for(l+=s->size,r+=s->size;l<r;l>>=1,r>>=1){
    if(l&1) res=calcMin(res,s->a[l++]);
    if(r&1) res=calcMin(res,s->a[--r]);
  }
  return res;
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

typedef struct heapNode{
  int l,r;
  node p;
} heapNode;

int cmp(const void *a,const void *b){
  return ((heapNode *)a)->p.val-((heapNode *)b)->p.val;
}

void run(void){
  int n;
  scanf("%d",&n);
  int *p=(int *)calloc(n,sizeof(int));
  int i;
  for(i=0;i<n;i++) scanf("%d",p+i);
  seg *even=newRMQ(n);
  seg *odd=newRMQ(n);
  for(i=0;i<n;i+=2) update(even,i,(node){p[i],i});
  for(i=1;i<n;i+=2) update(odd,i,(node){p[i],i});
  heap *h=newHeap(sizeof(heapNode),cmp);
  push(h,&((heapNode){0,n,query(even,0,n)}));
  int len=0;
  while(!isEmpty(h)){
    heapNode v;
    pop(h,&v);
    p[len++]=v.p.val;
    int c=v.p.index&1;
    update(c?odd:even,v.p.index,inf);
    node q=query(c?even:odd,v.p.index,v.r);
    p[len++]=q.val;
    update(c?even:odd,q.index,inf);
    if(v.p.index-v.l>0){
      push(h,&((heapNode){v.l,v.p.index,query(c?odd:even,v.l,v.p.index)}));
    }
    if(q.index-v.p.index-1>0){
      push(h,&((heapNode){v.p.index+1,q.index,query(c?even:odd,v.p.index+1,q.index)}));
    }
    if(v.r-q.index-1>0){
      push(h,&((heapNode){q.index+1,v.r,query(c?odd:even,q.index+1,v.r)}));
    }
  }
  for(i=0;i<n;i++) printf("%d ",p[i]);
  printf("\n");
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:146:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:149:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++) scanf("%d",p+i);
                    ^