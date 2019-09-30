#include <stdio.h>
int main(){
int n,i;
scanf ("%d",&n);
for (i=0;i<40000;i++){
if (i*i>n){
break;
}
}
printf ("%d",(i-1)*(i-1));
return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:1: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 scanf ("%d",&n);
 ^