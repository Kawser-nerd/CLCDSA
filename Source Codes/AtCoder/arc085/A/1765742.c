#include <stdio.h>
#include <math.h>
int N,M,a;
int main(void){
    scanf("%d%d",&N,&M);
    a=(1900*M+100*(N-M))*pow(2,M);
    printf("%d\n",a);
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&N,&M);
     ^