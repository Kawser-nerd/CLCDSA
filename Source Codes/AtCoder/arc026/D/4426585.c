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

typedef struct edge{
  int a,b;
  double c;
} edge;

int cmp(const void *a,const void *b){
  return ((edge *)a)->c<((edge *)b)->c?-1:1;
}

void run(void){
  int n,m;
  scanf("%d%d",&n,&m);
  int *a=(int *)calloc(4*m,sizeof(int));
  int *b=a+m;
  int *c=b+m;
  int *t=c+m;
  int i;
  for(i=0;i<m;i++) scanf("%d%d%d%d",a+i,b+i,c+i,t+i);
  double l=0;
  double r=1000000;
  edge *e=(edge *)calloc(m,sizeof(edge));
  UnionFind *u=newUnionFind(n);
  for(int iter=0;iter<60;iter++){
    double x=(l+r)/2;
    for(i=0;i<m;i++) e[i]=(edge){a[i],b[i],c[i]-x*t[i]};
    qsort(e,m,sizeof(edge),cmp);
    initUnionFind(u);
    double sum=0;
    for(i=0;i<m && e[i].c<=0;i++){
      unite(u,e[i].a,e[i].b);
      sum+=e[i].c;
    }
    for(;i<m && getSize(u,0)<n;i++){
      if(same(u,e[i].a,e[i].b)) continue;
      unite(u,e[i].a,e[i].b);
      sum+=e[i].c;
    }
    if(sum<=0){
      r=x;
    } else {
      l=x;
    }
  }
  printf("%.3f\n",(l+r)/2);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:58:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&m);
   ^
./Main.c:64:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<m;i++) scanf("%d%d%d%d",a+i,b+i,c+i,t+i);
                    ^