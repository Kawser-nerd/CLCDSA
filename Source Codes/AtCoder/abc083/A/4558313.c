#include<stdio.h>

int main(void){
int a,b,c,d;

scanf("%d %d %d %d",&a,&b,&c,&d);
if(a+b>c+d){
printf("Left");
}else if(c+d>a+b){
printf("Right");
}else{
printf("Balanced");
}

return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:1: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 scanf("%d %d %d %d",&a,&b,&c,&d);
 ^