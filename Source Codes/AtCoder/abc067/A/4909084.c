#include <stdio.h>
#include <string.h>
int main(){
  int a, b;

  scanf("%d%d", &a, &b);

  if(a % 3 == 0){
    printf("Possible");
  }else if(b % 3 == 0){
    printf("Possible");
  }else if((a + b) % 3 == 0){
    printf("Possible");
  }else{
    printf("Impossible");
  }
  printf("\n");
  
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d", &a, &b);
   ^