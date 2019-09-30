#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

#define POS(i,j) ((i)*n+(j))

const int inf=400*1000;

void dijkstra(int from,int *dp,int n,int *e){
  int used[400];
  int i,j;
  for(i=0;i<n;i++){
    dp[i]=inf;
    used[i]=0;
  }
  dp[from]=0;
  for(i=0;i<n;i++){
    int index=-1;
    for(j=0;j<n;j++){
      if(used[j]) continue;
      if(index==-1 || dp[index]>dp[j]){
	index=j;
      }
    }
    used[index]=1;
    for(j=0;j<n;j++){
      dp[j]=MIN(dp[j],dp[index]+e[POS(index,j)]);
    }
  }
  return;
}

void run(void){
  int n,m;
  scanf("%d%d",&n,&m);
  int *e=(int *)malloc(sizeof(int)*n*n);
  int i,j;
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      e[POS(i,j)]=(i==j?0:inf);
    }
  }
  for(i=0;i<m;i++){
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    a--;b--;
    e[POS(a,b)]=c;
    e[POS(b,a)]=c;
  }
  int *w=(int *)malloc(sizeof(int)*n*n);
  for(i=0;i<n*n;i++) w[i]=e[i];
  int k;
  for(k=0;k<n;k++){
    for(i=0;i<n;i++){
      for(j=0;j<n;j++){
	if(w[POS(i,k)]+w[POS(k,j)]>=w[POS(i,j)]) continue;
	w[POS(i,j)]=w[POS(i,k)]+w[POS(k,j)];
      }
    }
  }
  int *dpX=(int *)malloc(sizeof(int)*n);
  int *dpY=(int *)malloc(sizeof(int)*n);
  scanf("%d",&k);
  while(k--){
    int x,y,z;
    scanf("%d%d%d",&x,&y,&z);
    x--;y--;
    if(w[POS(x,y)]>z){
      e[POS(x,y)]=z;
      e[POS(y,x)]=z;
      dijkstra(x,dpX,n,e);
      dijkstra(y,dpY,n,e);
      for(i=0;i<n;i++){
	for(j=0;j<n;j++){
	  int min=MIN(dpX[i]+dpY[j],dpX[j]+dpY[i])+z;
	  w[POS(i,j)]=MIN(min,w[POS(i,j)]);
	}
      }
    }
    int64 sum=0;
    for(i=0;i<n;i++){
      for(j=i+1;j<n;j++){
	sum+=w[POS(i,j)];
      }
    }
    printf("%lld\n",sum);
  }
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:41:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&m);
   ^
./Main.c:51:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d",&a,&b,&c);
     ^
./Main.c:69:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&k);
   ^
./Main.c:72:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d",&x,&y,&z);
     ^