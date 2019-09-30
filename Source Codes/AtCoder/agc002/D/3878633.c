#include<stdio.h>
#include<stdlib.h>

typedef struct weightedUnionFind{
  int *parent;
  int *size;
  int n;
} UnionFind;

void initUnionFind(UnionFind *u){
  int i;
  for(i=0;i<u->n;i++){
    u->parent[i]=i;
    u->size[i]=1;
  }
}

UnionFind* newUnionFind(const int n){
  UnionFind *u=(UnionFind *)calloc(n,sizeof(UnionFind));
  u->parent=(int *)calloc(n,sizeof(int));
  u->size=(int *)calloc(n,sizeof(int));
  u->n=n;
  initUnionFind(u);
  return u;
}

int root(UnionFind *u,int x){
  if(u->parent[x]==x) return x;
  return u->parent[x]=root(u,u->parent[x]);
}

int same(UnionFind *u,int x,int y){
  return root(u,x)==root(u,y);
}

int getSize(UnionFind *u,int x){
  return u->size[root(u,x)];
}

void unite(UnionFind *u,int x,int y){
  x=root(u,x);
  y=root(u,y);
  if(x==y) return;
  u->parent[y]=x;
  u->size[x]+=u->size[y];
}

typedef struct vector{
  int *a;
  int len;
  int maxLen;
} vec;

void initVector(vec *v){
  if(v->a!=NULL){
    free(v->a);
    v->a=NULL;
  }
  v->len=0;
  v->maxLen=0;
}

vec* newVector(void){
  vec *v=(vec *)calloc(1,sizeof(vec));
  initVector(v);
  return v;
}

void add(vec *v,int x){
  if(v->len==v->maxLen){
    v->maxLen=v->maxLen*2+1;
    v->a=realloc(v->a,v->maxLen*sizeof(int));
  }
  v->a[v->len++]=x;
}

void run(void){
  int n,m;
  scanf("%d%d",&n,&m);
  int *a=(int *)calloc(m,sizeof(int));
  int *b=(int *)calloc(m,sizeof(int));
  int i;
  for(i=0;i<m;i++){
    scanf("%d%d",a+i,b+i);
    a[i]--;b[i]--;
  }
  int q;
  scanf("%d",&q);
  int *x=(int *)calloc(q,sizeof(int));
  int *y=(int *)calloc(q,sizeof(int));
  int *z=(int *)calloc(q,sizeof(int));
  for(i=0;i<q;i++){
    scanf("%d%d%d",x+i,y+i,z+i);
    x[i]--;y[i]--;
  }
  int *l=(int *)calloc(q,sizeof(int));
  int *r=(int *)calloc(q,sizeof(int));
  for(i=0;i<q;i++) r[i]=m;
  UnionFind *u=newUnionFind(n);
  vec **v=(vec **)calloc(m+1,sizeof(vec *));
  for(i=0;i<=m;i++) v[i]=newVector();
  while(1){
    for(i=0;i<=m;i++) initVector(v[i]);
    initUnionFind(u);
    int cnt=0;
    for(i=0;i<q;i++){
      if(r[i]-l[i]>1){
	int m=(l[i]+r[i])/2;
	add(v[m],i);
	cnt++;
      }
    }
    if(!cnt) break;
    for(i=0;i<m;i++){
      unite(u,a[i],b[i]);
      for(int j=0;j<v[i+1]->len;j++){
	int k=v[i+1]->a[j];
	int size=same(u,x[k],y[k])?getSize(u,x[k]):getSize(u,x[k])+getSize(u,y[k]);
	if(size>=z[k]){
	  r[k]=i+1;
	} else {
	  l[k]=i+1;
	}
      }
    }
  }
  for(i=0;i<q;i++){
    printf("%d\n",r[i]);
  }
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:79:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&m);
   ^
./Main.c:84:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",a+i,b+i);
     ^
./Main.c:88:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&q);
   ^
./Main.c:93:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d",x+i,y+i,z+i);
     ^