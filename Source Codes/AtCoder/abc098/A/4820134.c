#include <stdio.h>
int max(int a, int b){
    return (a > b) ? a : b;
}
int main(void){
    int A, B;
    scanf("%d%d", &A, &B);
    printf("%d\n", max(A + B, max(A - B, A * B)));
    return 0; 
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d", &A, &B);
     ^