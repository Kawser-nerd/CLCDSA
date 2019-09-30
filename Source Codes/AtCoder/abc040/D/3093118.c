#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

typedef struct enode{
  int a,b;
  int y;
} edge;

int cmp(const void *a,const void *b){
  return ((edge *)a)->y-((edge *)b)->y;
}

typedef struct qnode{
  int v;
  int w;
  int index;
  int res;
} node;

int cmpWeight(const void *a,const void *b){
  node *p=(node *)a;
  node *q=(node *)b;
  return p->w-q->w;
}

int cmpIndex(const void *a,const void *b){
  node *p=(node *)a;
  node *q=(node *)b;
  return p->index-q->index;
}

int root(int *u,int x){
  if(u[x]==x) return x;
  return u[x]=root(u,u[x]);
}

void unite(int *u,int *size,int x,int y){
  x=root(u,x);
  y=root(u,y);
  if(x==y) return;
  size[y]+=size[x];
  size[x]=0;
  u[x]=y;
  return;
}

void run(void){
  int n,m;
  scanf("%d%d",&n,&m);
  edge *e=(edge *)malloc(sizeof(edge)*m);
  int i;
  for(i=0;i<m;i++) scanf("%d%d%d",&e[i].a,&e[i].b,&e[i].y);
  qsort(e,m,sizeof(edge),cmp);
  int q;
  scanf("%d",&q);
  node *query=(node *)malloc(sizeof(node)*q);
  for(i=0;i<q;i++){
    scanf("%d%d",&query[i].v,&query[i].w);
    query[i].index=i;
  }
  qsort(query,q,sizeof(node),cmpWeight);
  int *u=(int *)malloc(sizeof(int)*(n+1));
  int *size=(int *)malloc(sizeof(int)*(n+1));
  for(i=1;i<=n;i++){
    u[i]=i;
    size[i]=1;
  }
  int j=m-1;
  for(i=q-1;i>=0;i--){
    while(j>=0 && e[j].y>query[i].w){
      unite(u,size,e[j].a,e[j].b);
      j--;
    }
    //{int k;for(k=1;k<=n;k++) printf("%d ",size[k]); printf("\n");}
    query[i].res=size[root(u,query[i].v)];
  }
  qsort(query,q,sizeof(node),cmpIndex);
  for(i=0;i<q;i++){
    printf("%d\n",query[i].res);
  }
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:56:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&m);
   ^
./Main.c:59:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<m;i++) scanf("%d%d%d",&e[i].a,&e[i].b,&e[i].y);
                    ^
./Main.c:62:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&q);
   ^
./Main.c:65:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&query[i].v,&query[i].w);
     ^