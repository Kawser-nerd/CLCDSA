#include <stdio.h>
int main(void){
    unsigned int a=0,b=0;
    scanf("%d",&a);
    if(a==12){
        b=1;
    }else{
        b=a+1;
    }
    printf("%d\n",b);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&a);
     ^