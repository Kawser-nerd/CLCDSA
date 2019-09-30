#include <stdio.h>
int main (){
int a,b;
scanf ("%d",&a);
  if (a%2==1){
  b=a+1;
  }
  else{
  b=a-1;
  }
printf ("%d\n",b);
return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:1: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 scanf ("%d",&a);
 ^