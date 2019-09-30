#include<stdio.h>
int main (){
int a,b;
scanf ("%d%d",&a,&b);
  if (a+b<10){
  printf ("%d",a+b);
  }
  else{
  printf ("error");
  }
return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:1: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 scanf ("%d%d",&a,&b);
 ^