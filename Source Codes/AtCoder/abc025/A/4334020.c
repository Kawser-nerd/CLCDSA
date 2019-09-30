#include<stdio.h>
int main (){
char a[5];
  int b,c,d;
  scanf ("%s",a);
  scanf ("%d",&b);
  b--;
  c=b/5;
  d=b-(c*5);
  printf ("%c%c\n",a[c],a[d]);
return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf ("%s",a);
   ^
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf ("%d",&b);
   ^