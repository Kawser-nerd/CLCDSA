#include <stdio.h>
int main(void){
    int a,d;
    scanf("%d%d",&a,&d);
    printf("%d\n",(a+1)*d>a*(d+1)?(a+1)*d:a*(d+1));
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&a,&d);
     ^