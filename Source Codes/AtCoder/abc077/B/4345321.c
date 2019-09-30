#include <stdio.h>
#include <math.h>
int main(void){
  double n;
  scanf("%lf",&n);
  int i;
  for(i=1;;i++){
    if(i*i>n){
      printf("%d",(i-1)*(i-1));
      return 0;
    }
  }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lf",&n);
   ^