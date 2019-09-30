#include <stdio.h>
#include <string.h>
int main(){
  char a[2], b[2];
 
  scanf("%s%s", a, b);
 
  if(strcmp(a, b) == 0){
    printf("H");
  }else{
    printf("D");
  }
 
  printf("\n");
  
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s%s", a, b);
   ^