#include <stdio.h>
int main(){
  long int n;
  scanf("%ld",&n);
  if(n%2){
    printf("%ld", n*2);
  }
  else{
    printf("%ld", n);
  }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%ld",&n);
   ^