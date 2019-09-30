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

int cmpInt(const void *a,const void *b){
  return *(int *)a-*(int *)b;
}

typedef struct sushi{
  int t,d;
} node;

int cmpSushi(const void *a,const void *b){
  return -(((node *)a)->d-((node *)b)->d);
}

void run(void){
  int n,k;
  scanf("%d%d",&n,&k);
  node *a=(node *)calloc(n,sizeof(node));
  int i;
  for(i=0;i<n;i++) scanf("%d%d",&a[i].t,&a[i].d);
  qsort(a,n,sizeof(node),cmpSushi);
  int *used=(int *)calloc(n+1,sizeof(int));
  heap *h=newHeap(sizeof(int),cmpInt);
  int cnt=0;
  int64 sum=0;
  for(i=0;i<k;i++){
    sum+=a[i].d;
    if(used[a[i].t]){
      push(h,&a[i].d);
    } else {
      used[a[i].t]=1;
      cnt++;
    }
  }
  int64 max=sum+(int64)cnt*cnt;
  for(i=k;i<n && !isEmpty(h);i++){
    if(used[a[i].t]) continue;
    used[a[i].t]=1;
    int v;
    pop(h,&v);
    sum-=v;
    sum+=a[i].d;
    cnt++;
    if(max<sum+(int64)cnt*cnt) max=sum+(int64)cnt*cnt;
  }
  printf("%lld\n",max);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:106:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&k);
   ^
./Main.c:109:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++) scanf("%d%d",&a[i].t,&a[i].d);
                    ^