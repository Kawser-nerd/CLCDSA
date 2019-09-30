#include <stdio.h>
int main (){
  int a,b,c;
  scanf ("%d%d%d",&a,&b,&c);
  if (a<=c & b>=c){
  printf ("Yes");
  }
  else {
  printf ("No");
  }
return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf ("%d%d%d",&a,&b,&c);
   ^