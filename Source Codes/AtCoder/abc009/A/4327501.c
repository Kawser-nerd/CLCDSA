#include <stdio.h>
int main(void){
    int N = 0;
    scanf("%d", &N);
    if(N % 2 == 1){
        printf("%d\n", N / 2 + 1);
    }else {
        printf("%d\n", N / 2);
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &N);
     ^