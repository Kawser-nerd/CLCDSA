#include <stdio.h>
int main(void){
    // Your code here!
    int a,d;
    scanf("%d%d",&a,&d);
    if((a+1)*d > (d+1)*a)
        printf("%d\n",(a+1)*d);
    else
        printf("%d\n",(d+1)*a);
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&a,&d);
     ^