#include <stdio.h>
int main (){
int n,a=0,b,i;
scanf ("%d",&n);
for (a;a<n;a++){   
b=a*a*a*a;
if (n==b){
break;
}
}
printf ("%d",a);
return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:1: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 scanf ("%d",&n);
 ^