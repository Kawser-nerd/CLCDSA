#include <stdio.h>
int main(){
    int a,b,h;
    scanf("%d%d%d",&a,&b,&h);
    printf("%d\n",(a+b)*h/2);
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d",&a,&b,&h);
     ^