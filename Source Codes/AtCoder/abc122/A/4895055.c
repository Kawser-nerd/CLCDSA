#include<stdio.h>
int main(void){
  char b;
  
  scanf("%c", &b);
  if(b == 'A')printf("T\n");
  else if(b == 'T')printf("A\n");
  else if(b == 'C')printf("G\n");
  else if(b == 'G')printf("C\n");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%c", &b);
   ^