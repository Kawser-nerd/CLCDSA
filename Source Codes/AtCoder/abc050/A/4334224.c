#include <stdio.h>
int main(){
int a,b;
char op;
scanf("%d %c %d",&a,&op,&b);
if (op=='+'){
printf("%d",a+b);
}
if (op=='-'){
printf("%d",a-b);
}
return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:1: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 scanf("%d %c %d",&a,&op,&b);
 ^