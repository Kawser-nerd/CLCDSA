#include<stdio.h>
int main(){
  int N;
  scanf("%d",&N);
  int M;
  if(N % 2 == 0){
    M = (N*(N - 1) - N)/2;
    printf("%d\n",M);
    for(int i = 0;i < N;i ++){
      for(int j = 0;j < i;j ++){
        if(j + i != N - 1){
          printf("%d %d\n",j +1,i +1);
        }
      }
    }
  }else{
    M = (N*(N-1)-N+1)/2;
    printf("%d\n",M);
    for(int i = 0;i < N;i ++){
      for(int j = 0;j < i;j ++){
        if(j + i != N - 2){
          printf("%d %d\n",j +1,i +1);
        }
      }
    }
  }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&N);
   ^