#include <stdio.h>
#include <string.h>
int main(){
  char s[101];

  scanf("AtCoder %s Contest", s);

  printf("A%cC\n", s[0]);


} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("AtCoder %s Contest", s);
   ^