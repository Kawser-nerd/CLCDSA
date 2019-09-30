#include<stdio.h>
int main (){
char s[100];
  int a;
  scanf ("%s",s);
  scanf ("%d",&a);
  printf ("%c",s[a-1]);
return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf ("%s",s);
   ^
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf ("%d",&a);
   ^