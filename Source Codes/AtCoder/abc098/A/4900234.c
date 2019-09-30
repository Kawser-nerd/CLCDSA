#include <stdio.h>
int main(){
int a,b,max;
scanf("%d",&a);
scanf("%d",&b);
max=a+b;
if(max<a-b){
max=a-b;
}
if(max<a*b){
max=a*b;
}
printf("%d\n",max);
} ./Main.c: In function ‘main’:
./Main.c:4:1: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 scanf("%d",&a);
 ^
./Main.c:5:1: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 scanf("%d",&b);
 ^