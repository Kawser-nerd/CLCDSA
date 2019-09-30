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

typedef struct charcount{
  int cnt[26];
  int l;
} node;

int cmp(const void *a,const void *b){
  int *x=((node *)a)->cnt;
  int *y=((node *)b)->cnt;
  int i;
  for(i=0;i<26;i++) if(x[i]!=y[i]) return x[i]-y[i];
  return 0;
}

void run(void){
  int n,k;
  scanf("%d%d",&n,&k);
  char *s=(char *)calloc(n+1,sizeof(char));
  scanf("%s",s);
  heap *h=newHeap(sizeof(node),cmp);
  node t;
  memset(&t,0,sizeof(node));
  int i;
  for(i=0;i<k;i++) t.cnt[s[i]-'a']++;
  t.l=0;
  push(h,&t);
  for(i=k;i<n;i++){
    t.cnt[s[i-k]-'a']--;
    t.cnt[s[i]-'a']++;
    t.l=i-k+1;
    push(h,&t);
  }
  int find=0;
  while(!isEmpty(h) && !find){
    node t;
    pop(h,&t);
    int min=t.l;
    int max=t.l;
    while(!isEmpty(h)){
      node s;
      top(h,&s);
      if(cmp(&s,&t)!=0) break;
      pop(h,&s);
      if(min>s.l) min=s.l;
      if(max<s.l) max=s.l;
    }
    if(max-min>=k) find=1;
  }
  printf("%s\n",find?"YES":"NO");
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:118:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&k);
   ^
./Main.c:120:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",s);
   ^