#include <stdio.h>

int main(int argc, char const *argv[]) {
    // ??
    int A, B;
    // ??
    scanf("%d %d", &A, &B );
    // ??
    printf("%d %d\n",B, A);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d", &A, &B );
     ^