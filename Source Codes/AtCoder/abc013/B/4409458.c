#include <stdio.h>
#include <math.h>
int main(void){
    // Your code here!
    int a,b,g;
    scanf("%d%d",&a,&b);
    g = fmin(abs(a-b),10-abs(a-b));
    printf("%d\n",g);
} ./Main.c: In function ‘main’:
./Main.c:7:14: warning: implicit declaration of function ‘abs’ [-Wimplicit-function-declaration]
     g = fmin(abs(a-b),10-abs(a-b));
              ^
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&a,&b);
     ^