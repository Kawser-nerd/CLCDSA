#include <stdio.h>
#include <string.h>

int main(){
  char a[15];
  char *b ="pp";
  scanf("%s",a);
  strcat(a,b);
  printf("%s\n",a);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",a);
   ^