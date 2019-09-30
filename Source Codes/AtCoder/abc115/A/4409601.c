#include <stdio.h>
int main(void){
    printf("Christmas");
    int D = 0;
    scanf("%d", &D);
    D = 25 - D;
    for (int i = 0; i < D; i++){
        printf(" Eve");
    }
    return 0; 
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &D);
     ^