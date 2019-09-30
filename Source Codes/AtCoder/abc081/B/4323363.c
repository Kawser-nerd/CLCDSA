#include<stdio.h>

int main(){
  int i,j,k=0;
  int N;
  scanf("%d",&N);
  int A[N];
  for(i=0;i<N;i++){
    scanf("%d ",&A[i]);
    if(A[i]%2 == 1){
      puts("0");
      return 0;
    }
  }
  
  while(1){
    for(i=0;i<N;i++){
      if(A[i] %2 == 1){
        printf("%d\n",k);
        return 0;
      }
      A[i] /=2;
    }
    k++;
  }
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&N);
   ^
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d ",&A[i]);
     ^