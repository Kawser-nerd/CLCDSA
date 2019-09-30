#include <stdio.h>
#include <math.h>
#include <stdlib.h>
typedef unsigned long long int llu;

int compare(const void* x, const void* y){
  if(*(int*)x<*(int*)y) return 1;
  else if(*(int*)x>*(int*)y) return -1;
  return 0;
}



int main(){
  int N,M;
  scanf("%d%d",&N,&M);
  int *A;
  int *Acost;
  int cost[10]={100,2,5,5,4,5,6,3,7,6};

  A=(int*)malloc(M*sizeof(int));
  Acost=(int*)malloc(M*sizeof(int));

  for(int i=0;i<M;i++){
   scanf("%d",&A[i]);
  }
  qsort(A,M,sizeof(int),compare);
  for(int i=0;i<M;i++) Acost[i]=cost[A[i]];

  int *dp;
  dp=(int*)malloc((N+1)*sizeof(int));
  dp[0]=0;
  for(int i=1;i<=N;i++){
    dp[i]=-10;
    for(int j=0;j<M;j++){
      if(i-Acost[j]>=0){
        if(dp[i-Acost[j]]!=-10){
          if(dp[i-Acost[j]]+1>dp[i]){
            dp[i]=dp[i-Acost[j]]+1;
          }
        }
      }
    }
  }
  /*for(int i=0;i<=N;i++){
    printf("dp[%2d]=%d\n",i,dp[i]);
  }
  for(int i=0;i<M;i++){
    printf("A[%d]=%d Acost[%d]=%d\n",i,A[i],i,Acost[i]);
  }*/

  while(N!=0){
    for(int i=0;i<M;i++){
      if(N-Acost[i]>=0){
        if(dp[N]==dp[N-Acost[i]]+1){
          printf("%d",A[i]);
          N=N-Acost[i];
          break;
        }
      }
    }
  }
  printf("\n");

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:16:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&N,&M);
   ^
./Main.c:25:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%d",&A[i]);
    ^