#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef long long int int64;

typedef struct pairingHeapNode{
  struct pairingHeapNode *next;
  struct pairingHeapNode *child;
  unsigned char val[];
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
  memcpy(v,h->root->val,h->size);
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
      pop(h,&t);
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
./Main.c:126:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&len);
   ^
./Main.c:131:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d",&l,&r,&c);
     ^