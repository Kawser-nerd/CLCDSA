#include <stdio.h>
#include <string.h>
int main(){
  int a, b;

  scanf("%d%d", &a, &b);

  printf("%d", (a + b) % 24 );
  
  printf("\n");
  
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d", &a, &b);
   ^