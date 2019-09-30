#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void){
char a[100];
  int n;
  scanf("%s",&a);
  n=strlen(a);
  if(a[n-1]=='T'){printf("YES");}
  else{printf("NO");}
return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:9: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘char (*)[100]’ [-Wformat=]
   scanf("%s",&a);
         ^
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",&a);
   ^