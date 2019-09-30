#include <stdio.h>

int main(void){
    int N, K; 
    scanf("%d%d", &N, &K);
    printf("%d\n", (N%K > 0) ? 1 : 0);
    return 0; 
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d", &N, &K);
     ^