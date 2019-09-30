#include <stdio.h>

int main(){
    int a,b,h,sum=0;
    scanf("%d%d%d",&a,&b,&h);
    sum+=(a+b)*h/2;
    printf("%d\n",sum);
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d",&a,&b,&h);
     ^