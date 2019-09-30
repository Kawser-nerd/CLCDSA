#include<stdio.h>
#include<stdlib.h>

#define POS(i,j) ((i)*w+(j))

const int mod=1000000007;
const int d[]={0,1,0,-1};
int h,w;
int *a=NULL;
int *dp=NULL;

int calc(int i,int j){
  if(dp[POS(i,j)]>=0) return dp[POS(i,j)];
  int local=1;
  int k;
  for(k=0;k<4;k++){
    int x=i+d[k];
    int y=j+d[k^1];
    if(x>=0 && x<h && y>=0 && y<w && a[POS(i,j)]<a[POS(x,y)]){
      local=(local+calc(x,y))%mod;
    }
  }
  dp[POS(i,j)]=local;
  return local;
}

void run(void){
  scanf("%d%d",&h,&w);
  a=(int *)malloc(sizeof(int)*h*w);
  int i;
  for(i=0;i<h*w;i++) scanf("%d",a+i);
  dp=(int *)malloc(sizeof(int)*h*w);
  for(i=0;i<h*w;i++) dp[i]=-1;
  for(i=0;i<h*w;i++) calc(i/w,i%w);
  int ans=0;
  for(i=0;i<h*w;i++) ans=(ans+dp[i])%mod;
  printf("%d\n",ans);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:28:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&h,&w);
   ^
./Main.c:31:22: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<h*w;i++) scanf("%d",a+i);
                      ^