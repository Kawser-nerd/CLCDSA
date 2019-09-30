# include <stdio.h>

int main(){
  int X,A,B;
  scanf("%d%d%d",&X,&A,&B);
  printf("%d\n",(X-A)%B);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d",&X,&A,&B);
   ^