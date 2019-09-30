#include<stdio.h>
#include<stdlib.h>

#define MAX(a,b) ((a)>(b)?(a):(b))
#define POS(i,j) ((i)*(w+1)+(j))

void run(void){
  int w,n,k;
  scanf("%d%d%d",&w,&n,&k);
  int *dp=(int *)calloc((w+1)*(k+1),sizeof(int));
  int i,j,l;
  for(i=0;i<n;i++){
    int a,b;
    scanf("%d%d",&a,&b);
    for(j=k-1;j>=0;j--){
      for(l=0;l<=w-a;l++){
	dp[POS(j+1,l+a)]=MAX(dp[POS(j+1,l+a)],dp[POS(j,l)]+b);
      }
    }
  }
  int max=0;
  for(i=0;i<=k;i++){
    for(j=0;j<=w;j++){
      max=MAX(dp[POS(i,j)],max);
    }
  }
  printf("%d\n",max);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d",&w,&n,&k);
   ^
./Main.c:14:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&a,&b);
     ^