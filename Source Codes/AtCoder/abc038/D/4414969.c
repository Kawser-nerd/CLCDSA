#include<stdio.h>
#include<stdlib.h>

typedef struct item{
  int h,w;
} node;

int cmp(const void *a,const void *b){
  node *p=(node *)a;
  node *q=(node *)b;
  if(p->w!=q->w) return p->w-q->w;
  return q->h-p->h;
}

void run(void){
  int n;
  scanf("%d",&n);
  node *p=(node *)calloc(n,sizeof(node));
  int i;
  for(i=0;i<n;i++){
    int h,w;
    scanf("%d%d",&h,&w);
    p[i]=(node){h,w};
  }
  qsort(p,n,sizeof(node),cmp);
  int *dp=(int *)calloc(n+1,sizeof(int));
  int len=0;
  for(i=0;i<n;i++){
    if(dp[len]<p[i].h){
      dp[++len]=p[i].h;
      continue;
    }
    int l=0;
    int r=len+1;
    while(r-l>1){
      int m=(l+r)/2;
      if(dp[m]<p[i].h){
	l=m;
      } else {
	r=m;
      }
    }
    dp[r]=p[i].h;
  }
  printf("%d\n",len);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:17:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:22:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&h,&w);
     ^