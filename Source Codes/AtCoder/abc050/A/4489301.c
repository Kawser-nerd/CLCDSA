#include <stdio.h>
#include <string.h>
int main(){
  int a, b;
  char c[2];

  scanf("%d %c %d", &a, c, &b);

  if(c[0] == '+' ){
    printf("%d\n", a + b);
  }else if(c[0] == '-'){
    printf("%d\n", a - b);
  }

} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %c %d", &a, c, &b);
   ^