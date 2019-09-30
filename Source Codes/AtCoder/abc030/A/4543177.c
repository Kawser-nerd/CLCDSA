#include <stdio.h>
int main(void){
    // Your code here!
    float a,b,c,d;
    scanf("%f%f%f%f",&a,&b,&c,&d);
    if (b/a == d/c)
        printf("DRAW\n");
    else if(b/a > d/c)
        printf("TAKAHASHI\n");
    else
        printf("AOKI\n");
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%f%f%f%f",&a,&b,&c,&d);
     ^