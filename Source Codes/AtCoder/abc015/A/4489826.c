#include <stdio.h>
#include <string.h>

int main(void){
  char a[50],b[50];
  scanf("%s%s",a,b);

  if(strlen(a) > strlen(b)) printf("%s\n",a);
  else printf("%s\n",b);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s%s",a,b);
   ^