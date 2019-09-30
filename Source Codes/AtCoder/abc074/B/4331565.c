#include<stdio.h>
#include<math.h>

int main(){
  int i,j,k=0;
  int N,K;
  scanf("%d",&N);
  scanf("%d",&K);
  
  int A[N];
  
  for(i=0;i<N;i++){
    scanf("%d ",&A[i]);
  }
  
  for(i=0;i<N;i++){
    if(A[i] > abs(A[i]-K)){
      k+=abs(A[i]-K)*2;
    }
    else
      k+=A[i]*2;
  }
  
  printf("%d\n",k);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:17:15: warning: implicit declaration of function ‘abs’ [-Wimplicit-function-declaration]
     if(A[i] > abs(A[i]-K)){
               ^
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&N);
   ^
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&K);
   ^
./Main.c:13:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d ",&A[i]);
     ^