#include <stdio.h>
int main (){
int min=1000,a,i,b;
scanf ("%d",&b);
for (i=0;i<b;i++){
scanf ("%d",&a);
if (min>a){
min=a;
}
}
printf ("%d\n",min);
return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:1: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 scanf ("%d",&b);
 ^
./Main.c:6:1: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 scanf ("%d",&a);
 ^