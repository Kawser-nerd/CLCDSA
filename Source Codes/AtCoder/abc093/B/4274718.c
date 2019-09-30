#include<stdio.h>

int main(){
  int A,B,K;
  int i,j,k;
  scanf("%d %d %d",&A,&B,&K);
  if(B-A+1 <=K*2){
    for(i=A;i<=B;i++)
      printf("%d\n",i);
    return 0;
  }
  
  for(i=A;i<A+K;i++){
    printf("%d\n",i);
  }
  
  for(i=B-K+1;i<=B;i++)
    printf("%d\n",i);
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %d",&A,&B,&K);
   ^