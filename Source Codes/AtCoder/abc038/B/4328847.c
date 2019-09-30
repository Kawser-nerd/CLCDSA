#include <stdio.h>
int main (){
int a,b,x,y,k=0;
scanf ("%d%d%d%d",&a,&b,&x,&y);
if (a==x || b==x || a==y || b==y){
k=1;
}
  if (k==1){
  printf ("YES\n");
  }
  else {
  printf ("NO\n");
  }
return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:1: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 scanf ("%d%d%d%d",&a,&b,&x,&y);
 ^