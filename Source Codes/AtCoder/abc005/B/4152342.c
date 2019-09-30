#include <stdio.h>

int main(){
  int i,N,T[101],min;
  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&T[i]);
    if(i==0){
      min=T[i];
    }else{
      if(min>T[i])min=T[i];
    }
  }
  printf("%d\n",min);
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&N);
   ^
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&T[i]);
     ^