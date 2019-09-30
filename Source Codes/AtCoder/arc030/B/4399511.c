#include<stdio.h>
#include<stdlib.h>

#define POS(i,j) ((i)*n+(j))

void run(void){
  int n,x;
  scanf("%d%d",&n,&x);
  x--;
  int *h=(int *)calloc(n,sizeof(int));
  int i;
  for(i=0;i<n;i++) scanf("%d",h+i);
  int *g=(int *)calloc(n*n,sizeof(int));
  for(i=1;i<n;i++){
    int a,b;
    scanf("%d%d",&a,&b);
    a--;b--;
    g[POS(a,b)]=g[POS(b,a)]=1;
  }
  int *q=(int *)calloc(n,sizeof(int));
  int *parent=(int *)calloc(n,sizeof(int));
  parent[x]=x;
  int front=0,last=0;
  q[last++]=x;
  while(last<n){
    int v=q[front++];
    for(i=0;i<n;i++){
      if(i!=parent[v] && g[POS(i,v)]==1){
	q[last++]=i;
	parent[i]=v;
      }
    }
  }
  int *dp=(int *)calloc(n,sizeof(int));
  for(i=n-1;i>=0;i--){
    int v=q[i];
    int sum=0;
    int j;
    for(j=0;j<n;j++){
      if(g[POS(v,j)]==1 && j!=parent[v] && (dp[j]>0 || h[j]==1)){
	sum+=dp[j]+2;
      }
    }
    dp[v]=sum;
  }
  printf("%d\n",dp[x]);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&x);
   ^
./Main.c:12:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++) scanf("%d",h+i);
                    ^
./Main.c:16:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&a,&b);
     ^