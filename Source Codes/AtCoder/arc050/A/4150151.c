#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
 
int main(void){

  char C[2], c[2];

  scanf("%s%s", C, c);

  if(C[0] + ('a' - 'A') == c[0]){
    printf("Yes\n");
  }else{
    printf("No\n");
  }
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s%s", C, c);
   ^