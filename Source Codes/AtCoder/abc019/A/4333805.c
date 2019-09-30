#include<stdio.h>
int main (){
int a,b,c,h,k;
scanf ("%d%d%d",&a,&b,&c);
  if (a>b){
  h=a;
  a=b;
  b=h;
  }
  if (b>c){
  k=b;
  b=c;
  c=k;
  }
  if (a>b){
  h=a;
  a=b;
  b=h;
  }
  printf ("%d\n",b);
return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:1: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 scanf ("%d%d%d",&a,&b,&c);
 ^