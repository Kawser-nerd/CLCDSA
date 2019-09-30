#include <stdio.h>
int main(void){
    int a,b,c,min=0;
    scanf("%d%d%d",&a,&b,&c);
    min=a+b;
    if(min>a+c) min=a+c;
    if(min>b+c) min=b+c;
    printf("%d",min);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d",&a,&b,&c);
     ^