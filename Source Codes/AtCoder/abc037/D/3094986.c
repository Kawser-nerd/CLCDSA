#include<stdio.h>
#include<stdlib.h>

typedef long long int int64;

#define POS(i,j) ((i)*w+(j))

typedef struct point2d{
  int i,j;
  int val;
} node;

int cmp(const void *a,const void *b){
  return ((node *)a)->val-((node *)b)->val;
}

void run(void){
  int h,w;
  scanf("%d%d",&h,&w);
  int *a=(int *)malloc(sizeof(int)*h*w);
  node *array=(node *)malloc(sizeof(node)*h*w);
  int i,j;
  for(i=0;i<h;i++){
    for(j=0;j<w;j++){
      scanf("%d",a+POS(i,j));
      array[POS(i,j)].i=i;
      array[POS(i,j)].j=j;
      array[POS(i,j)].val=a[POS(i,j)];
    }
  }
  qsort(array,h*w,sizeof(node),cmp);
  int ans=0;
  int *dp=(int *)malloc(sizeof(int)*h*w);
  const int mod=1000000007;
  int d[]={1,0,-1,0};
  for(i=h*w-1;i>=0;i--){
    int x=array[i].i;
    int y=array[i].j;
    int local=1;
    int k;
    for(k=0;k<4;k++){
      int nx=x+d[k];
      int ny=y+d[k^1];
      if(0<=nx && nx<h && 0<=ny && ny<w && a[POS(x,y)]<a[POS(nx,ny)]){
	local=(local+dp[POS(nx,ny)])%mod;
      }
    }
    dp[POS(x,y)]=local;
    ans=(ans+dp[POS(x,y)])%mod;
  }
  printf("%d\n",ans);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:19:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&h,&w);
   ^
./Main.c:25:7: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
       scanf("%d",a+POS(i,j));
       ^