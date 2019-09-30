#include<stdio.h>
int main(void){
  int N,i,j;
  int A[100]={0};
  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }
  for(i=0;i<N-1;i++){
    for(j=i+1;j<N;j++){
      if(A[i]<A[j]){
    	int t=A[i];
    	A[i]=A[j];
    	A[j]=t;
  		}
    }
  }
  printf("%d\n",A[0]-A[N-1]);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&N);
   ^
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&A[i]);
     ^