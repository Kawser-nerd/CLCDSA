#include <stdio.h>
int main (){
char a[11],b[11],c[11];
  int h;
  scanf ("%s%s%s",a,b,c);
h='A'-'a';
printf ("%c%c%c",a[0]+h,b[0]+h,c[0]+h);
return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf ("%s%s%s",a,b,c);
   ^