#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct directedGraph{
  int *vertex;
  int *next;
  int *start;
  int v,e;
  int pointer;
} graph;

graph* newGraph(const int v,const int e){
  graph *g=(graph *)malloc(sizeof(graph));
  g->vertex=(int *)calloc(e,sizeof(int));
  g->next=(int *)calloc(e,sizeof(int));
  g->start=(int *)calloc(v,sizeof(int));
  for(int i=0;i<v;i++) g->start[i]=-1;
  g->v=v;
  g->e=e;
  g->pointer=0;
  return g;
}

void freeGraph(graph *g){
  free(g->vertex);
  free(g->next);
  free(g->start);
  free(g);
  return;
}

void addEdge(graph *g,const int from,const int to){
  const int p=g->pointer;
  g->vertex[p]=to;
  g->next[p]=g->start[from];
  g->start[from]=p;
  g->pointer++;
  return;
}

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

typedef struct node{
  int index;
  int val;
} node;

int cmp(const void *a,const void *b){
  return ((node *)a)->val-((node *)b)->val;
}

void run(void){
  int n,m;
  scanf("%d%d",&n,&m);
  graph *g=newGraph(n,2*m);
  graph *f=newGraph(n,2*m);
  while(m--){
    int c,a,b;
    scanf("%d%d%d",&c,&a,&b);
    if(c==0){
      addEdge(g,a,b);
      addEdge(g,b,a);
    } else {
      addEdge(f,a,b);
      addEdge(f,b,a);
    }
  }
  int *now=(int *)calloc(n,sizeof(int));
  int *next=(int *)calloc(n,sizeof(int));
  int *used=(int *)calloc(n,sizeof(int));
  int *stack=(int *)calloc(n,sizeof(int));
  int i;
  for(i=0;i<n;i++) now[i]=n*n;
  now[0]=0;
  memcpy(next,now,sizeof(int)*n);
  heap *h=newHeap(sizeof(node),cmp);
  push(h,&((node){0,0}));
  int k=0;
  while(!isEmpty(h)){
    int top=0;
    while(!isEmpty(h)){
      node t;
      pop(h,&t);
      const int v=t.index;
      if(used[v]) continue;
      used[v]=1;
      stack[top++]=v;
      for(int p=g->start[v];p!=-1;p=g->next[p]){
	const int u=g->vertex[p];
	if(now[u]<=now[v]+1) continue;
	next[u]=now[u]=now[v]+1;
	push(h,&((node){u,now[u]}));
      }
    }
    for(i=0;i<top;i++){
      const int v=stack[i];
      for(int p=f->start[v];p!=-1;p=f->next[p]){
	const int u=f->vertex[p];
	if(next[u]<=now[v]+k+1) continue;
	next[u]=now[v]+k+1;
	push(h,&((node){u,next[u]}));
      }
    }
    for(i=0;i<top;i++){
      const int v=stack[i];
      used[v]=0;
      for(int p=f->start[v];p!=-1;p=f->next[p]){
	const int u=f->vertex[p];
	now[u]=next[u];
      }
    }
    k++;
  }
  for(i=0;i<n;i++) printf("%d\n",now[i]);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:151:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&m);
   ^
./Main.c:156:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d",&c,&a,&b);
     ^