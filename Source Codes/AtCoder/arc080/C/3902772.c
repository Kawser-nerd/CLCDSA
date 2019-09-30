#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct RangeMinQuery{
  int *array;
  int size;
} RMQ;

const int inf=1000000;

RMQ* newRMQ(const int n){
  int k=1;
  while(k<n) k*=2;
  RMQ *res=(RMQ *)calloc(1,sizeof(RMQ));
  res->array=(int *)calloc(2*k,sizeof(int));
  res->size=k;
  int i;
  for(i=1;i<2*k;i++) res->array[i]=inf;
  return res;
}

int min(int a,int b){
  return a<b?a:b;
}

void update(RMQ *seg,int index,int val){
  int x=index+seg->size;
  seg->array[x]=val;
  x/=2;
  while(x>=1){
    seg->array[x]=min(seg->array[2*x],seg->array[2*x+1]);
    x>>=1;
  }
}

void query(RMQ *seg,int l,int r,int *resVal,int *resIndex){
  int x=l+seg->size;
  int y=r+seg->size;
  int ans=inf;
  while(x<y){
    if(x&1) ans=min(ans,seg->array[x++]);
    if(y&1) ans=min(ans,seg->array[--y]);
    x>>=1;
    y>>=1;
  }
  *resVal=ans;
  typedef struct parameter{
    int k,l,r;
  } node;
  node stack[32];
  int top=0;
  stack[top++]=(node){1,0,seg->size};
  while(top>0){
    const node p=stack[--top];
    if(p.r<=l) continue;
    if(seg->array[p.k]>ans) continue;
    if(p.k>=seg->size){
      *resIndex=p.l;
      return;
    }
    const int m=(p.l+p.r)/2;
    stack[top++]=(node){2*p.k+1,m  ,p.r};
    stack[top++]=(node){2*p.k  ,p.l,m  };
  }
  exit(1);
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
  int val,index;
} heapNode;

int cmp(const void *a,const void *b){
  return ((heapNode *)a)->val-((heapNode *)b)->val;
}

void run(void){
  int n;
  scanf("%d",&n);
  int *p=(int *)calloc(n,sizeof(int));
  int i;
  for(i=0;i<n;i++) scanf("%d",p+i);
  RMQ *even=newRMQ(n);
  RMQ *odd=newRMQ(n);
  for(i=0;i<n;i++) update(i&1?odd:even,i,p[i]);
  heap *h=newHeap(sizeof(heapNode),cmp);
  int val,index;
  query(even,0,n,&val,&index);
  push(h,&((heapNode){0,n,val,index}));
  int len=0;
  while(!isEmpty(h)){
    heapNode v;
    pop(h,&v);
    p[len++]=v.val;
    RMQ *s=(v.l%2==0?even:odd);
    RMQ *t=(v.l%2==0?odd:even);
    query(t,v.index,v.r,&val,&index);
    p[len++]=val;
    update(s,v.index,inf);
    update(t,index,inf);
    int a,b;
    if(v.index-v.l>0){
      query(s,v.l,v.index,&a,&b);
      push(h,&((heapNode){v.l,v.index,a,b}));
    }
    if(index-v.index>1){
      query(t,v.index+1,index,&a,&b);
      push(h,&((heapNode){v.index+1,index,a,b}));
    }
    if(v.r-index>1){
      query(s,index+1,v.r,&a,&b);
      push(h,&((heapNode){index+1,v.r,a,b}));
    }
  }
  for(i=0;i<n;i++) printf("%d ",p[i]);
  printf("\n");
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:165:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:168:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++) scanf("%d",p+i);
                    ^