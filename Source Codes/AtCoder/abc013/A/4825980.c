#include <stdio.h>
#include <string.h>

int main(){
  char a;
  scanf("%c",&a);
  printf("%d\n",a-'0'-16);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%c",&a);
   ^