#include <stdio.h>

int main() {
    int A, B, C;
    scanf("%d%d%d", &A, &B, &C);
    printf("%d\n", C <= A+B ? B+C
                 : A+B+B+1);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d", &A, &B, &C);
     ^