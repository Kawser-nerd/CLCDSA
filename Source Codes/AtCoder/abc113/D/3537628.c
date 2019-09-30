#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

const int mod=1000000007;

void calc(int index,int *edge,int w,int *now,int *next){
  if(index>=w-1){
    int i;
    for(i=0;i<w;i++){
      if(i+1<w && edge[i]){
	next[i]+=now[i+1];
      } else if(i-1>=0 && edge[i-1]){
	next[i]+=now[i-1];
      } else {
	next[i]+=now[i];
      }
      next[i]%=mod;
    }
    return;
  }
  calc(index+1,edge,w,now,next);
  edge[index]=1;
  calc(index+2,edge,w,now,next);
  edge[index]=0;
  return;
}

void run(void){
  int h,w,k;
  scanf("%d%d%d",&h,&w,&k);
  int *dp=(int *)calloc(2*w,sizeof(int));
  int now=0;
  dp[0]=1;
  for(int i=1;i<=h;i++){
    int next=now^w;
    for(int j=0;j<w;j++) dp[next+j]=0;
    int edge[8]={0,0,0,0,0,0,0,0};
    calc(0,edge,w,dp+now,dp+next);
    now=next;
  }
  printf("%d\n",dp[now+k-1]);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:37:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d",&h,&w,&k);
   ^