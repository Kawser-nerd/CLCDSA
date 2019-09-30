#include<stdio.h>

int main(void){
  long int i,n;
  scanf("%ld",&n);
  for(i=0;;i++){
    if(i*i>n) break;
  }
  printf("%ld\n",(i-1)*(i-1));
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%ld",&n);
   ^