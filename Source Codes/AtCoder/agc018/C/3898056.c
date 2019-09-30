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

typedef struct coins{
  int a,b,c;
} node;

int cmpAB(const void *a,const void *b){
  node *p=(node *)a;
  node *q=(node *)b;
  return (p->b-p->a)-(q->b-q->a);
}

int cmpAC(const void *a,const void *b){
  node *p=(node *)a;
  node *q=(node *)b;
  return -((p->c-p->a)-(q->c-q->a));
}

int cmpBC(const void *a,const void *b){
  node *p=(node *)a;
  node *q=(node *)b;
  return -((p->c-p->b)-(q->c-q->b));
}

void run(void){
  int x,y,z;
  scanf("%d%d%d",&x,&y,&z);
  const int n=x+y+z;
  node *p=(node *)calloc(n,sizeof(node));
  int i;
  for(i=0;i<n;i++){
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    p[i]=(node){a,b,c};
  }
  qsort(p,n,sizeof(node),cmpAB);
  int64 *front=(int64 *)calloc(z+1,sizeof(int64));
  int64 *back=(int64 *)calloc(z+1,sizeof(int64));
  heap *h=newHeap(sizeof(node),cmpAC);
  int64 sum=0;
  for(i=0;i<x;i++){
    sum+=p[i].a;
    push(h,p+i);
  }
  front[0]=sum;
  for(i=x;i<n-y;i++){
    sum+=p[i].a;
    push(h,p+i);
    node t;
    pop(h,&t);
    sum+=t.c-t.a;
    front[i-x+1]=sum;
  }
  freeHeap(h);
  h=newHeap(sizeof(node),cmpBC);
  sum=0;
  for(i=n-1;i>=n-y;i--){
    sum+=p[i].b;
    push(h,p+i);
  }
  back[z]=sum;
  for(i=n-y-1;i>=x;i--){
    sum+=p[i].b;
    push(h,p+i);
    node t;
    pop(h,&t);
    sum+=t.c-t.b;
    back[i-x]=sum;
  }
  int64 max=0;
  for(i=0;i<=z;i++) {
    int64 t=front[i]+back[i];
    if(max<t) max=t;
  }
  printf("%lld\n",max);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:116:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d",&x,&y,&z);
   ^
./Main.c:122:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d",&a,&b,&c);
     ^