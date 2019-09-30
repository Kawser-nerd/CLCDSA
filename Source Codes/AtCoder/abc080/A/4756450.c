#include <stdio.h>
int main(){
  int N,A,B,result;
  scanf("%d %d %d",&N,&A,&B);
  
  result = N*A;
  //printf("%d,%d\n",result,B);
  
  if(result < B) printf("%d\n",result);
  else printf("%d\n",B);
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %d",&N,&A,&B);
   ^