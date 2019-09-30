#include <stdio.h>

int main(void){
    int N;
    scanf("%d",&N);
    if(N!=12)   printf("%d\n",N+1);
    else        printf("%d\n",1);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&N);
     ^