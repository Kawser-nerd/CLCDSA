#include <stdio.h>
int main(void){
int i;
  char s[100];
  scanf("%s %d",s,&i);
  printf("%c",s[i-1]);
  
return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s %d",s,&i);
   ^