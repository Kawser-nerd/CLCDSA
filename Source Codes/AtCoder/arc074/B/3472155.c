#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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

void freeOneNode(heapNode *t){
  free(t);
  return;
}

void freeAllNode(heapNode *t){
  if(t==NULL) return;
  freeAllNode(t->next);
  freeAllNode(t->child);
  freeOneNode(t);
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

void clearHeap(heap *h){
  freeAllNode(h->root);
  h->root=NULL;
  h->heapSize=0;
}

int getSize(const heap *h){
  return h->heapSize;
}

int isEmpty(const heap *h){
  return getSize(h)==0;
}

void top(const heap *h,void *res){
  memcpy(res,h->root->val,h->size);
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
  freeOneNode(h->root);
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

typedef long long int int64;

int cmp(const void *a,const void *b){
  return *(int *)a-*(int *)b;
}

void run(void){
  int n;
  scanf("%d",&n);
  int *a=(int *)calloc(3*n,sizeof(int));
  int i;
  for(i=0;i<3*n;i++) scanf("%d",a+i);
  int64 *front=(int64 *)calloc(n+1,sizeof(int64));
  heap *h=newHeap(sizeof(int),cmp);
  int64 sum=0;
  for(i=0;i<n;i++){
    sum+=a[i];
    push(h,a+i);
  }
  front[0]=sum;
  for(i=n;i<2*n;i++){
    sum+=a[i];
    push(h,a+i);
    int v;
    pop(h,&v);
    sum-=v;
    front[i-n+1]=sum;
  }
  clearHeap(h);
  int64 *back=(int64 *)calloc(n+1,sizeof(int64));
  sum=0;
  for(i=3*n-1;i>=2*n;i--){
    sum+=a[i];
    int v=-a[i];
    push(h,&v);
  }
  back[n]=sum;
  for(i=2*n-1;i>=n;i--){
    sum+=a[i];
    int v=-a[i];
    push(h,&v);
    pop(h,&v);
    sum+=v;
    back[i-n]=sum;
  }
  int64 max=front[0]-back[0];
  for(i=1;i<=n;i++) if(max<front[i]-back[i]) max=front[i]-back[i];
  printf("%lld\n",max);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:115:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:118:22: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<3*n;i++) scanf("%d",a+i);
                      ^