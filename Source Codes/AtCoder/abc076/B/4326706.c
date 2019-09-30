#include<stdio.h>

int main(){
  int K,N;
  scanf("%d",&N);
  scanf("%d",&K);
  
  int i,j,k=1;
  
  for(i=0;i<N;i++){
    if(k*2 < k + K)
      k *= 2;
    else
      k +=K;
  }
  
  printf("%d\n",k);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&N);
   ^
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&K);
   ^