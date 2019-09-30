#include <stdio.h>

int main(void){
  long X,Y,Z;
  scanf("%ld%ld%ld",&X,&Y,&Z);

  long ans = 0;

  while(Z+(Y+Z)*ans <= X){
    ans++;
  }

  printf("%ld\n",ans-1);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%ld%ld%ld",&X,&Y,&Z);
   ^