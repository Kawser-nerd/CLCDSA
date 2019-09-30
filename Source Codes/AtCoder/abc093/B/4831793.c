#include <stdio.h>

int main(void){
    int A, B, K;
    scanf("%d%d%d", &A, &B, &K);
    int tmp = A;
    for(int i = 0; i < K; i++){
        tmp = A+i;
        if(tmp > B) return 0;
        printf("%d\n", tmp);
    }
    for(int i = 0; i < K; i++){
        if(B-K+i+1 <= tmp) continue;
        printf("%d\n", B - K + i + 1);
    }
    return 0; 
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d", &A, &B, &K);
     ^