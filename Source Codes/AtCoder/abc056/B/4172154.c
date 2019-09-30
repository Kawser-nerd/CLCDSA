#include <stdio.h>
#include <stdlib.h>
int main (){
int a,b,c,k;
 scanf ("%d%d%d",&a,&b,&c);
k= abs( b-c );
if (a<k){
printf ("%d",k-a);
}
  else{
  printf ("0");
  }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf ("%d%d%d",&a,&b,&c);
  ^