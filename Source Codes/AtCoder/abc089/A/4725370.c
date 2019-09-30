#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    int n;
    scanf("%d",&n);
    printf("%d\n",n/3);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^