#include<stdio.h>

int main(void){

int n;
scanf("%d", &n);
printf("ABC%d\n", n);
return 0;
} ./Main.c: In function �main�:
./Main.c:6:1: warning: ignoring return value of �scanf�, declared with attribute warn_unused_result [-Wunused-result]
 scanf("%d", &n);
 ^