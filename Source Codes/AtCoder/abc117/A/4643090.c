#include <stdio.h>
int main(void){
    int T, X;
    scanf("%d %d", &T, &X);
    double t = (double) T / X;
    printf("%f\n", t);
    return 0; 
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d", &T, &X);
     ^