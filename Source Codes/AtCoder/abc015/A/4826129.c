#include <stdio.h>
#include <string.h>
int main(){
  char a[55],b[55];
  scanf("%s\n%s",a,b);
  
  if( strlen(a) > strlen(b)) printf("%s\n",a);
  else printf("%s\n",b);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s\n%s",a,b);
   ^