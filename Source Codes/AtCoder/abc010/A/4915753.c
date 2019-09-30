#include <stdio.h>
int main(void){
   char S[10];
   
   scanf("%s",S);
   
   printf("%spp",S);
  
  return(0);
} ./Main.c: In function ‘main’:
./Main.c:5:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%s",S);
    ^