#include<stdio.h>
#include<stdlib.h>

typedef struct splaNodee{
  int t;
  int color;
  int vertex;
  int rad;
} node;

int cmp(const node *a,const node *b){
  return a->t>=b->t;
}

typedef struct binaryHeap{
  node *h;
  int heapSize;
  int (*cmp)(const node *,const node *);
} heap;

heap* newHeap(int maxSize,int (*cmpF)(const node *,const node *)){
  heap *res=(heap *)malloc(sizeof(heap));
  res->h=(node *)malloc(sizeof(node)*(maxSize+1));
  res->heapSize=0;
  res->cmp=cmpF;
  return res;
}

void push(heap *q,node *p){
  //printf("push : %d %d %d %d\n",p->vertex,p->rad,p->color,p->t);
  q->heapSize+=1;
  node *h=q->h;
  int k=q->heapSize;
  int (*cmp)(const node *,const node *)=q->cmp;
  h[k]=*p;
  while(k>1){
    if(cmp(h+k/2,h+k)) return;
    node swap=h[k];
    h[k]=h[k/2];
    h[k/2]=swap;
    k/=2;
  }
  return;
}

void pop(heap *q,node *res){
  node *h=q->h;
  *res=h[1];
  h[1]=h[q->heapSize];
  q->heapSize-=1;
  int n=q->heapSize;
  int k=1;
  while(2*k+1<=n){
    int next=cmp(h+2*k,h+2*k+1)?2*k:2*k+1;
    if(cmp(h+k,h+next)) return;
    node swap=h[k];
    h[k]=h[next];
    h[next]=swap;
    k=next;
  }
  if(2*k<=n && cmp(h+2*k,h+k)){
    node swap=h[k];
    h[k]=h[2*k];
    h[2*k]=swap;
  }
  //node *p=res;printf("pop : %d %d %d %d\n",p->vertex,p->rad,p->color,p->t);
  return;
}

void assign(int a,int b,int *vertex,int *next,int *start,int index){
  vertex[index]=b;
  next[index]=start[a];
  start[a]=index;
  return;
}

void run(void){
  int n,m;
  scanf("%d%d",&n,&m);
  int *vertex=(int *)malloc(sizeof(int)*2*m);
  int *next=(int *)malloc(sizeof(int)*2*m);
  int *start=(int *)malloc(sizeof(int)*n);
  int i;
  for(i=0;i<n;i++) start[i]=-1;
  for(i=0;i<m;i++){
    int a,b;
    scanf("%d%d",&a,&b);
    a--;b--;
    assign(a,b,vertex,next,start,2*i);
    assign(b,a,vertex,next,start,2*i+1);
  }
  int q;
  scanf("%d",&q);
  heap *h=newHeap(11*(n+m+q),cmp);
  for(i=1;i<=q;i++){
    int v,d,c;
    scanf("%d%d%d",&v,&d,&c);
    v--;
    node t={i,c,v,d};
    push(h,&t);
  }
  int *rad=(int *)malloc(sizeof(int)*n);
  int *ans=(int *)malloc(sizeof(int)*n);
  for(i=0;i<n;i++){
    rad[i]=-1;
    ans[i]=0;
  }
  while(h->heapSize>0){
    node t;
    pop(h,&t);
    int r=t.rad;
    int v=t.vertex;
    if(r<rad[v]) continue;
    rad[v]=r;
    if(ans[v]==0) ans[v]=t.color;
    r--;
    t.rad=r;
    if(r<0) continue;
    int p;
    for(p=start[v];p!=-1;p=next[p]){
      int u=vertex[p];
      if(r<=rad[u]) continue;
      rad[u]=r;
      t.vertex=u;
      push(h,&t);
    }
  }
  for(i=0;i<n;i++) printf("%d\n",ans[i]);
  return;
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:79:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&m);
   ^
./Main.c:87:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&a,&b);
     ^
./Main.c:93:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&q);
   ^
./Main.c:97:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d",&v,&d,&c);
     ^