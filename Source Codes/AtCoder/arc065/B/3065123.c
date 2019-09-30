#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

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

typedef struct mnode{
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
  int *road=(int *)malloc(sizeof(int)*n);
  int i;
  for(i=0;i<n;i++) road[i]=i;
  for(i=0;i<k;i++){
    int p,q;
    scanf("%d%d",&p,&q);
    unite(road,p-1,q-1);
  }
  int *rail=(int *)malloc(sizeof(int)*n);
  for(i=0;i<n;i++) rail[i]=i;
  for(i=0;i<l;i++){
    int r,s;
    scanf("%d%d",&r,&s);
    unite(rail,r-1,s-1);
  }
  node *array=(node *)malloc(sizeof(node)*n);
  for(i=0;i<n;i++){
    array[i].x=root(road,i);
    array[i].y=root(rail,i);
    array[i].index=i;
  }
  qsort(array,n,sizeof(node),cmp);
  int *ans=(int *)malloc(sizeof(int)*n);
  for(i=0;i<n;i++){
    int j=i;
    while(j<n && cmp((void *)(array+i),(void *)(array+j))==0) j++;
    int k;
    for(k=i;k<j;k++) ans[array[k].index]=j-i;
    i=j-1;
  }
  for(i=0;i<n;i++) printf("%d ",ans[i]);
  printf("\n");
  return;
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:41:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d",&n,&k,&l);
   ^
./Main.c:47:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&p,&q);
     ^
./Main.c:54:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&r,&s);
     ^