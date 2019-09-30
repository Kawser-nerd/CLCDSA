#include <stdio.h>

int main(void){
    int N,A,B;
    scanf("%d",&N);
    if (N==1){
        printf("Hello World");
    } else {
        scanf("%d",&A);
        scanf("%d",&B);
        printf("%d",A+B);
    }

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&N);
     ^
./Main.c:9:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&A);
         ^
./Main.c:10:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&B);
         ^