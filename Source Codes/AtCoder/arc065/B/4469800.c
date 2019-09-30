#include<stdio.h>
#include<stdlib.h>

typedef struct UnionFind{
  int *parent;
  int n;
} UnionFind;

UnionFind* newUnionFind(int n){
  UnionFind *u=(UnionFind *)calloc(1,sizeof(UnionFind));
  u->parent=(int *)calloc(n,sizeof(int));
  u->n=n;
  for(int i=0;i<n;i++) u->parent[i]=-1;
  return u;
}

void freeUnionFind(UnionFind *u){
  free(u->parent);
  free(u);
}

void initUnionFind(UnionFind *u){
  for(int i=0;i<u->n;i++) u->parent[i]=-1;
}

int root(UnionFind *u,int x){
  if(u->parent[x]<0) return x;
  return u->parent[x]=root(u,u->parent[x]);
}

int same(UnionFind *u,int x,int y){
  return root(u,x)==root(u,y);
}

int getSize(UnionFind *u,int x){
  return -u->parent[root(u,x)];
}

void unite(UnionFind *u,int x,int y){
  x=root(u,x);
  y=root(u,y);
  if(x==y) return;
  if(u->parent[x]>u->parent[y]){
    int swap=x;
    x=y;
    y=swap;
  }
  u->parent[x]+=u->parent[y];
  u->parent[y]=x;
}

typedef struct node{
  int x,y;
  int index;
} node;

int cmp(const void *a,const void *b){
  node *p=(node *)a;
  node *q=(node *)b;
  if(p->x!=q->x) return p->x-q->x;
  return p->y-q->y;
}

void run(void){
  int n,k,l;
  scanf("%d%d%d",&n,&k,&l);
  UnionFind *a=newUnionFind(n);
  while(k--){
    int p,q;
    scanf("%d%d",&p,&q);
    unite(a,p-1,q-1);
  }
  UnionFind *b=newUnionFind(n);
  while(l--){
    int r,s;
    scanf("%d%d",&r,&s);
    unite(b,r-1,s-1);
  }
  node *p=(node *)calloc(n,sizeof(node));
  int i;
  for(i=0;i<n;i++) p[i]=(node){root(a,i),root(b,i),i};
  qsort(p,n,sizeof(node),cmp);
  int *ans=(int *)calloc(n,sizeof(int));
  i=0;
  int j=0;
  while(i<n){
    while(j<n && cmp(p+i,p+j)==0) j++;
    for(int x=i;x<j;x++) ans[p[x].index]=j-i;
    i=j;
  }
  for(i=0;i<n;i++) printf("%d%c",ans[i]," \n"[i==n-1]);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:66:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d",&n,&k,&l);
   ^
./Main.c:70:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&p,&q);
     ^
./Main.c:76:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&r,&s);
     ^