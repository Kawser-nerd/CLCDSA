#include <stdio.h>

int main(void){
    int N, D, X;
    scanf("%d%d%d", &N, &D, &X);
    int A[N];
    for(int i = 0; i < N; i++){
        scanf("%d", &A[i]);
        X += (D-1) / A[i] + 1;
    }
    printf("%d\n", X);
    return 0; 
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d", &N, &D, &X);
     ^
./Main.c:8:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d", &A[i]);
         ^