#include <stdio.h>
#include <string.h>
int main(){
  int a, b, c, d;

  scanf("%d%d%d%d", &a, &b, &c, &d);

  if(a*b >= c*d){
    printf("%d", a * b);
  }else if(a*b < c*d){
    printf("%d", c * d);
  }
  printf("\n");
  
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d%d", &a, &b, &c, &d);
   ^