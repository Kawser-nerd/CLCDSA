#include <stdio.h>

int main(){
  int a;
  double sum=0;
  scanf("%d", &a);
  
  for(int i=1; i<a+1; i++){
    sum += i*10000.0 / a;
  }
  printf("%lf", sum);
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &a);
   ^