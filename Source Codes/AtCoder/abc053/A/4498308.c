#include <stdio.h>
#include <string.h>
int main(){
  int x;

  scanf("%d", &x);

  if(x < 1200){
    printf("ABC");
  }else{
    printf("ARC");
  }
  printf("\n");
  
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &x);
   ^