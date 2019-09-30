#include <stdio.h>

int main(){
  int N;
  scanf("%d",&N);
  if(N%2 == 0) printf("%d\n",N/2);
  else printf("%d\n",N/2+1);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&N);
   ^