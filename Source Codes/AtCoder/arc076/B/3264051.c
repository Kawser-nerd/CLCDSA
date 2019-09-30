#include<stdio.h>
#include<stdlib.h>

typedef long long int int64;

int *x=NULL;
int *y=NULL;

int cmpX(const void *a,const void *b){
  return x[*(int *)a]-x[*(int *)b];
}

int cmpY(const void *a,const void *b){
  return y[*(int *)a]-y[*(int *)b];
}

typedef struct minedge{
  int v;
  int a,b;
} edge;

int cmpEdge(const void *a,const void *b){
  edge *p=(edge *)a;
  edge *q=(edge *)b;
  return p->v-q->v;
}

int root(int *u,int k){
  if(u[k]==k) return k;
  return u[k]=root(u,u[k]);
}

int same(int *u,int a,int b){
  return root(u,a)==root(u,b);
}

void unite(int *u,int a,int b){
  a=root(u,a);
  b=root(u,b);
  if(a==b) return;
  u[a]=b;
  return;
}

void run(void){
  int n;
  scanf("%d",&n);
  x=(int *)malloc(sizeof(int)*n);
  y=(int *)malloc(sizeof(int)*n);
  int *index=(int *)malloc(sizeof(int)*n);
  int i;
  for(i=0;i<n;i++){
    scanf("%d%d",x+i,y+i);
    index[i]=i;
  }
  edge *e=(edge *)malloc(sizeof(edge)*2*(n-1));
  int len=0;
  qsort(index,n,sizeof(int),cmpX);
  for(i=0;i<n-1;i++){
    int a=index[i];
    int b=index[i+1];
    e[len].v=x[b]-x[a];
    e[len].a=a;
    e[len].b=b;
    len++;
  }
  qsort(index,n,sizeof(int),cmpY);
  for(i=0;i<n-1;i++){
    int a=index[i];
    int b=index[i+1];
    e[len].v=y[b]-y[a];
    e[len].a=a;
    e[len].b=b;
    len++;
  }
  qsort(e,len,sizeof(edge),cmpEdge);
  int *u=(int *)malloc(sizeof(int)*n);
  for(i=0;i<n;i++) u[i]=i;
  int64 sum=0;
  for(i=0;i<len;i++){
    int a=e[i].a;
    int b=e[i].b;
    if(same(u,a,b)) continue;
    sum+=e[i].v;
    unite(u,a,b);
  }
  printf("%lld\n",sum);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:47:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:53:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",x+i,y+i);
     ^