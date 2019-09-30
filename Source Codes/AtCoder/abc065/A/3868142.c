#include<stdio.h>
int main (){
int a,b,c;
scanf ("%d%d%d",&a,&b,&c);
  if (b>=c){
  printf ("delicious");
  }
  else if (a+b>=c){
  printf ("safe");
  }
  else{
  printf ("dangerous");
  }
return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:1: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 scanf ("%d%d%d",&a,&b,&c);
 ^