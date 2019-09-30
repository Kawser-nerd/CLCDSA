#include <stdio.h>
int main (){
int a,b,c=0,d=0,i;
scanf ("%d%d",&a,&b);
for (i=0;i<a;i++){
scanf ("%d",&d);
if (d<b-d){
  c=c+d;
}
else{
  c=c+b-d;
}
}
printf ("%d",c*2);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:1: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 scanf ("%d%d",&a,&b);
 ^
./Main.c:6:1: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 scanf ("%d",&d);
 ^