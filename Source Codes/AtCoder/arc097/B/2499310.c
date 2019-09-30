#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

int find(int *a,int x){
  if(a[x]==x) return x;
  a[x]=find(a,a[x]);
  return a[x];
}

int same(int *a,int x,int y){
  return find(a,x)==find(a,y);
}

void merge(int *a,int x,int y){
  x=find(a,x);
  y=find(a,y);
  if(x==y) return;
  a[x]=y;
  return;
}

void run(void){
  int n,m;
  scanf("%d%d",&n,&m);
  int p[100001];
  int i;
  for(i=1;i<=n;i++) scanf("%d",p+i);
  int a[100001];
  for(i=1;i<=n;i++) a[i]=i;
  for(i=0;i<m;i++){
    int x,y;
    scanf("%d%d",&x,&y);
    merge(a,x,y);
  }
  int cnt=0;
  for(i=1;i<=n;i++){
    if(same(a,i,p[i])) cnt++;
  }
  printf("%d\n",cnt);
  return;
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:31:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&m);
   ^
./Main.c:34:21: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=1;i<=n;i++) scanf("%d",p+i);
                     ^
./Main.c:39:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&x,&y);
     ^