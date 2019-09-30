#include <stdio.h>
int main (){
char s;
  scanf ("%c",&s);
  printf ("%d\n",s-'A'+1);  
return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf ("%c",&s);
   ^