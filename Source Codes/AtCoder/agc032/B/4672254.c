#include <stdio.h>

int main(void) {
  int N,M,ans[9901];
  scanf("%d",&N);
  if(N%2==1){
    printf("%d\n",(N-1)*(N-1)/2);
    for(int i=1;i<=N-1;i++){
      for(int j=i+1;j<=N;j++){
        if(i+j!=N){printf("%d %d\n",i,j);}
      }
    }
  }else{
    printf("%d\n",(N-2)*N/2);
    for(int i=1;i<=N-1;i++){
      for(int j=i+1;j<=N;j++){
        if(i+j!=N+1){printf("%d %d\n",i,j);}
      }
    }
  }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&N);
   ^