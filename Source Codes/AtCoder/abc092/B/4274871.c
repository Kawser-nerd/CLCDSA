#include<stdio.h>

int main(){

  int i,j,k;
  int N,D,X;
  int s=0;
  
  scanf("%d",&N);
  scanf("%d %d",&D,&X);
  int A[N];
  int B[N];
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
	B[i]=A[i];
  }   
  
  s += N;
  
  for(i=2;i<=D;i++){
    for(j=0;j<N;j++){
      if((i) == A[j]+1){
        s++;
        A[j]+=B[j];
      }
    }
  }
  
  printf("%d\n",s+X);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&N);
   ^
./Main.c:10:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&D,&X);
   ^
./Main.c:14:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&A[i]);
     ^