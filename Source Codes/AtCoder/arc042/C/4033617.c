#include<stdio.h>
#include<stdlib.h>

#define MAX(a,b) ((a)>(b)?(a):(b))

typedef struct item{
  int v;
  int w;
} node;

int cmp(const void *a,const void *b){
  return ((node *)a)->w-((node *)b)->w;
}

void run(void){
  int n,p;
  scanf("%d%d",&n,&p);
  node *q=(node *)calloc(n,sizeof(node));
  int i;
  for(i=0;i<n;i++) scanf("%d%d",&q[i].w,&q[i].v);
  qsort(q,n,sizeof(node),cmp);
  int *dp=(int *)calloc(p+1,sizeof(node));
  int max=0;
  for(i=n-1;i>=0;i--){
    max=MAX(max,dp[p]+q[i].v);
    for(int j=p;j>=q[i].w;j--){
      dp[j]=MAX(dp[j],dp[j-q[i].w]+q[i].v);
    }
  }
  printf("%d\n",max);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:17:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&p);
   ^
./Main.c:20:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++) scanf("%d%d",&q[i].w,&q[i].v);
                    ^