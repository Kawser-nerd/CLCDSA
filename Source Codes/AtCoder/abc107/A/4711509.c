#include <stdio.h>

int main(void){
    int N, i; 
    scanf("%d%d", &N, &i);
    printf("%d\n", N - i + 1);
    return 0; 
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d", &N, &i);
     ^