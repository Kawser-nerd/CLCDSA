#include<stdio.h>
#include<math.h>

int main(){
  int i,j,k=0;
  int X,N;
  
  scanf("%d %d",&N,&X);
  
  int A[N];
  for(i=0;i<N;i++){
    scanf("%d ",&A[i]);
    k+=A[i];
  }
  X -= k;

  int tmp;
  for (i=0; i<N; ++i) {
    for (j=i+1; j<N; ++j) {
      if (A[i] > A[j]) {
        tmp =  A[i];
        A[i] = A[j];
        A[j] = tmp;
      }
    }
  }


  printf("%d\n",(int)(X/A[0])+N);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&N,&X);
   ^
./Main.c:12:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d ",&A[i]);
     ^