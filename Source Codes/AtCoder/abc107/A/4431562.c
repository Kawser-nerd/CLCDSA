#include<stdio.h>

int main(void){
    int a,b;
    scanf("%d %d\n",&a,&b);
    printf("%d\n",a-b+1);
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d\n",&a,&b);
     ^