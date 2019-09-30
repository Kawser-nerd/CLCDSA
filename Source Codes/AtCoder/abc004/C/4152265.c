#include <stdio.h>

int main(){
  int N,i,tmp,ind;
  int D[]={1,2,3,4,5,6};
  scanf("%d",&N);
  N%=30;
  for(i=0;i<N;i++){
    ind=i%5;
    tmp=D[ind];
    D[ind]=D[ind+1];
    D[ind+1]=tmp;
  }
  for(i=0;i<6;i++)printf("%d",D[i]);
  printf("\n");
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&N);
   ^