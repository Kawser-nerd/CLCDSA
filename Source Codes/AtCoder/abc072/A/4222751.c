#include <stdio.h>

long max(long a,long b){
  if(a > b){
    return a;
  }
  return b;
}

int main(void){
  long X,t;
  scanf("%ld%ld",&X,&t);


  printf("%ld\n",max(0,X-t));

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:12:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%ld%ld",&X,&t);
   ^