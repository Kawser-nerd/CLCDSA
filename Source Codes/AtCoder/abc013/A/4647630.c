#include <stdio.h>

int main(void) {
  char x;
  scanf("%c",&x);
  
  switch (x){
    case 'A': printf("1\n"); break;
    case 'B': printf("2\n");break;
    case 'C': printf("3\n");break;
    case 'D': printf("4\n");break;
    case 'E':printf("5\n");break;
    defalut: return 0;
  }
  return 0;
  
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%c",&x);
   ^