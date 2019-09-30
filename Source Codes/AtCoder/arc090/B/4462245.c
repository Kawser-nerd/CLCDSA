#include<stdio.h>
#include<stdlib.h>

typedef struct WeightedUnionFind{
  int *parent;
  int *distance;
  int n;
} UnionFind;

UnionFind* newUnionFind(int n){
  UnionFind *u=(UnionFind *)calloc(1,sizeof(UnionFind));
  u->parent=(int *)calloc(2*n,sizeof(int));
  u->distance=u->parent+n;
  u->n=n;
  int i;
  for(i=0;i<n;i++){
    u->parent[i]=i;
    u->distance[i]=0;
  }
  return u;
}

int root(UnionFind *u,int x){
  if(u->parent[x]==x) return x;
  int p=u->parent[x];
  u->parent[x]=root(u,u->parent[x]);
  u->distance[x]+=u->distance[p];
  return u->parent[x];
}

int same(UnionFind *u,int x,int y){
  return root(u,x)==root(u,y);
}

int weight(UnionFind *u,int x){
  root(u,x);
  return u->distance[x];
}

int diff(UnionFind *u,int x,int y){
  return weight(u,y)-weight(u,x);
}

void unite(UnionFind *u,int x,int y,int w){
  w+=weight(u,x);
  w-=weight(u,y);
  x=root(u,x);
  y=root(u,y);
  if(x==y) return;
  u->parent[y]=x;
  u->distance[y]+=w;
}

void run(void){
  int n,m;
  scanf("%d%d",&n,&m);
  UnionFind *u=newUnionFind(n+1);
  while(m--){
    int l,r,d;
    scanf("%d%d%d",&l,&r,&d);
    if(!same(u,l,r)){
      unite(u,l,r,d);
    } else if(diff(u,l,r)!=d){
      puts("No");
      return;
    }
  }
  puts("Yes");
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:56:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&m);
   ^
./Main.c:60:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d",&l,&r,&d);
     ^