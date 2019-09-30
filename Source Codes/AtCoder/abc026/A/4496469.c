#include <stdio.h>
#include <math.h>
int main(void){
    // Your code here!
    int n;
    scanf("%d",&n);
    printf("%f\n",pow(n/2,2));
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^