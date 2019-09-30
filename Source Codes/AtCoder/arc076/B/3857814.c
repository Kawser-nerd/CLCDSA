#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct pairingHeapNode{
  struct pairingHeapNode *next;
  struct pairingHeapNode *child;
  unsigned long long int val[];
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
  if(v!=NULL) memcpy(v,h->root->val,h->size);
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
./Main.c:142:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:148:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&a,&b);
     ^