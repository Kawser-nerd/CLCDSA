#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct binaryHeap{
  void *h;
  int heapSize;
  int maxSize;
  size_t size;
  int (*cmp)(const void *,const void *);
} heap;

heap* newHeap(const size_t size,int (*cmpF)(const void *,const void *)){
  const int maxSize=1;
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

inline void heapFunc_swap(void * restrict a,void * restrict b,void * restrict tmp,size_t size){
  memcpy(tmp,a,size);
  memcpy(a,b,size);
  memcpy(b,tmp,size);
  return;
}

void push(heap *q,const void *p){
  if(q->heapSize==q->maxSize){
    q->h=realloc(q->h,q->size*(2*q->maxSize+1));
    q->maxSize*=2;
  }
  q->heapSize+=1;
  void *h=q->h;
  int k=q->heapSize;
  const size_t size=q->size;
  int (*cmp)(const void *,const void *)=q->cmp;
  memcpy(h+k*size,p,size);
  while(k>1){
    if(cmp(h+(k/2)*size,h+k*size)<=0) return;
    heapFunc_swap(h+(k/2)*size,h+k*size,h,size);
    k/=2;
  }
  return;
}

void pop(heap *q,void *res){
  void *h=q->h;
  const size_t size=q->size;
  if(res!=NULL) memcpy(res,h+size,size);
  memcpy(h+size,h+size*q->heapSize,size);
  q->heapSize-=1;
  int (*cmp)(const void *,const void *)=q->cmp;
  const int n=q->heapSize;
  int k=1;
  while(2*k+1<=n){
    int next=cmp(h+2*k*size,h+(2*k+1)*size)<=0?2*k:2*k+1;
    if(cmp(h+k*size,h+next*size)<=0) return;
    heapFunc_swap(h+k*size,h+next*size,h,size);
    k=next;
  }
  if(2*k<=n && cmp(h+k*size,h+2*k*size)>0) heapFunc_swap(h+k*size,h+2*k*size,h,size);
  return;
}

void top(const heap *q,void *res){
  memcpy(res,q->h+q->size,q->size);
  return;
}

typedef long long int int64;

typedef struct inode{
  int a,b,c;
} node;

int cmp(const void *a,const void *b){
  return ((node *)a)->c-((node *)b)->c;
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
  int n,m;
  scanf("%d%d",&n,&m);
  heap *h=newHeap(sizeof(node),cmp);
  int i;
  for(i=0;i<n;i++){
    int c;
    scanf("%d",&c);
    push(h,&((node){0,i+1,c}));
  }
  for(i=0;i<m;i++){
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    push(h,&((node){a,b,c}));
  }
  int *u=(int *)calloc(n+1,sizeof(int));
  for(i=0;i<=n;i++) u[i]=i;
  int64 ans=0;
  int cnt=0;
  while(cnt<n){
    node t;
    pop(h,&t);
    if(same(u,t.a,t.b)) continue;
    unite(u,t.a,t.b);
    ans+=t.c;
    cnt++;
  }
  printf("%lld\n",ans);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:117:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&m);
   ^
./Main.c:122:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&c);
     ^
./Main.c:127:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d",&a,&b,&c);
     ^