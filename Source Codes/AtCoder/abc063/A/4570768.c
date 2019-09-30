#include <stdio.h>
#include <string.h>
int main(){
  int a, b;

  scanf("%d%d", &a, &b);

  if(a + b >= 10){
    printf("error");
  }else{
    printf("%d", a + b);
  }

  printf("\n");
  
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d", &a, &b);
   ^