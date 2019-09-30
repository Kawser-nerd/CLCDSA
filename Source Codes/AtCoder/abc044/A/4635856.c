#include<stdio.h>

int main(){
  int N,K,X,Y;
  scanf("%d %d %d %d",&N,&K,&X,&Y);
  if(N <= K) printf("%d",N*X);
  else printf("%d",K*X+(N-K)*Y);
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %d %d",&N,&K,&X,&Y);
   ^