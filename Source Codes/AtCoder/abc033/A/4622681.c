#include <stdio.h>
int main(){
int a;
scanf("%d",&a);
if(a%1111==0){printf("SAME\n");}
else {printf("DIFFERENT\n");}

return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:1: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 scanf("%d",&a);
 ^