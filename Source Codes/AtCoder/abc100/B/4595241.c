#include <stdio.h>
int main (){
  int a,b,c;
  scanf ("%d%d",&a,&b);
  c=(b-b%100)/100;
  if (a==0){
  printf ("%d",b+c);
  }
  else if (a==1){
  printf ("%d",100*(b+c));
  }
  else {
  printf ("%d",10000*(b+c));
  }
return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf ("%d%d",&a,&b);
   ^