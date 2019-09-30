#include<stdio.h>
int main (){
int a,b;
scanf ("%d%d",&a,&b);
  if (a==2 || b==2){
  printf ("No");
  }
  else {
  if (a==4 || a==6 || a==9 || a==11){
  if (b==4 || b==6 || b==9 || b==11){
  printf ("Yes");
  }
  else {printf ("No");}
  }
  else{
  if(b==4 || b==6 || b==9 || b==11){
  printf ("No");
  }
    else{
    printf ("Yes");
    }
  }
  }
return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:1: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 scanf ("%d%d",&a,&b);
 ^