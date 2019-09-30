#include <stdio.h>
int main(){
int A,B;
scanf("%d %d",&A,&B);
if(B%A==0)
printf("%d",A+B);
else
printf("%d",B-A);
return(0);
} ./Main.c: In function ‘main’:
./Main.c:4:1: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 scanf("%d %d",&A,&B);
 ^