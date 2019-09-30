#include <stdio.h>
int main(void){
char a[10];
char b[10];
char c[10];
 int add;
  add='A'-'a';
  scanf("%s %s %s",a,b,c);
  a[0]=a[0]+add;
  b[0]=b[0]+add;
  c[0]=c[0]+add;
  printf("%c%c%c",a[0],b[0],c[0]);
return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s %s %s",a,b,c);
   ^