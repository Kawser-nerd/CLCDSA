#include<stdio.h>
#include<stdlib.h>

typedef long long int int64;

typedef struct inode{
  int a,b,c;
} node;

int cmp(const void *a,const void *b){
  return ((node *)a)->c-((node *)b)->c;
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
  node *array=(node *)calloc(n+m,sizeof(node));
  int i;
  for(i=0;i<n;i++){
    int c;
    scanf("%d",&c);
    array[i]=(node){0,i+1,c};
  }
  for(i=0;i<m;i++){
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    array[i+n]=(node){a,b,c};
  }
  qsort(array,n+m,sizeof(node),cmp);
  int *u=(int *)calloc(n+1,sizeof(int));
  for(i=0;i<=n;i++) u[i]=i;
  int64 ans=0;
  int cnt=0;
  for(i=0;cnt<n;i++){
    if(same(u,array[i].a,array[i].b)) continue;
    unite(u,array[i].a,array[i].b);
    ans+=array[i].c;
    cnt++;
  }
  printf("%lld\n",ans);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:32:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&m);
   ^
./Main.c:37:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&c);
     ^
./Main.c:42:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d",&a,&b,&c);
     ^