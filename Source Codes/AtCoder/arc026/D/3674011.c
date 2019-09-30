#include<stdio.h>
#include<stdlib.h>

typedef struct {
  double val;
  int index;
} node;

int cmp(const void *a,const void *b){
  double p=((node *)a)->val;
  double q=((node *)b)->val;
  return p==q?0:p<q?-1:1;
}

int root(int *u,int x){
  if(u[x]==x) return x;
  return u[x]=root(u,u[x]);
}

int same(int *u,int x,int y){
  return root(u,x)==root(u,y);
}

void unite(int *u,int x,int y){
  x=root(u,x);
  y=root(u,y);
  if(x==y) return;
  u[x]=y;
}

void run(void){
  int n,m;
  scanf("%d%d",&n,&m);
  int *a=(int *)calloc(m,sizeof(int));
  int *b=(int *)calloc(m,sizeof(int));
  int *c=(int *)calloc(m,sizeof(int));
  int *t=(int *)calloc(m,sizeof(int));
  int i;
  for(i=0;i<m;i++) scanf("%d%d%d%d",a+i,b+i,c+i,t+i);
  int *u=(int *)calloc(n,sizeof(int));
  node *d=(node *)calloc(m,sizeof(node));
  double l=0;
  double r=1000000;
  for(int iter=0;iter<60;iter++){
    double mid=(l+r)/2;
    for(i=0;i<m;i++) d[i]=(node){c[i]-mid*t[i],i};
    qsort(d,m,sizeof(node),cmp);
    for(i=0;i<n;i++) u[i]=i;
    double sum=0;
    for(i=0;i<m && d[i].val<=0;i++){
      sum+=d[i].val;
      int k=d[i].index;
      unite(u,a[k],b[k]);
    }
    for(;i<m && d[i].val+sum<=0;i++){
      int k=d[i].index;
      if(same(u,a[k],b[k])) continue;
      unite(u,a[k],b[k]);
      sum+=d[i].val;
    }
    for(i=1;i<n;i++) if(!same(u,0,i)) break;
    if(i<n){
      l=mid;
    } else {
      r=mid;
    }
  }
  printf("%.3lf\n",(l+r)/2);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:33:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&m);
   ^
./Main.c:39:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<m;i++) scanf("%d%d%d%d",a+i,b+i,c+i,t+i);
                    ^