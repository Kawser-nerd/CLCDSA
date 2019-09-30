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

int cmpMin(const void *a,const void *b){
  return *(int *)a-*(int *)b;
}

int cmpMax(const void *a,const void *b){
  return -cmpMin(a,b);
}

void run(void){
  int n;
  scanf("%d",&n);
  int *a=(int *)calloc(3*n,sizeof(int));
  int i;
  for(i=0;i<3*n;i++) scanf("%d",a+i);
  heap *h=newHeap(sizeof(int),cmpMin);
  int64 sum=0;
  for(i=0;i<n;i++){
    sum+=a[i];
    push(h,a+i);
  }
  int64 *front=(int64 *)calloc(n+1,sizeof(int64));
  front[0]=sum;
  for(i=0;i<n;i++){
    sum+=a[n+i];
    push(h,a+n+i);
    int v;
    pop(h,&v);
    sum-=v;
    front[i+1]=sum;
  }
  sum=0;
  freeHeap(h);
  h=newHeap(sizeof(int),cmpMax);
  for(i=n-1;i>=0;i--){
    sum+=a[2*n+i];
    push(h,a+2*n+i);
  }
  int64 *back=(int64 *)calloc(n+1,sizeof(int64));
  back[0]=sum;
  for(i=n-1;i>=0;i--){
    sum+=a[n+i];
    push(h,a+n+i);
    int v;
    pop(h,&v);
    sum-=v;
    back[n-i]=sum;
  }
  freeHeap(h);
  int64 max=-1000000000LL*n;
  for(i=0;i<=n;i++){
    int64 t=front[i]-back[n-i];
    if(t>max) max=t;
  }
  printf("%lld\n",max);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:102:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:105:22: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<3*n;i++) scanf("%d",a+i);
                      ^