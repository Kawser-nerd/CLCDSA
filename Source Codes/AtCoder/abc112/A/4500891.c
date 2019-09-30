#include <stdio.h>

int main(void){
    int N;
    scanf("%d", &N);
    if(N == 1)printf("%s\n", "Hello World");
    if(N == 2){
        int A, B;
        scanf("%d\n%d", &A, &B);
        printf("%d\n", A+B);
    }
    return 0; 
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &N);
     ^
./Main.c:9:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d\n%d", &A, &B);
         ^