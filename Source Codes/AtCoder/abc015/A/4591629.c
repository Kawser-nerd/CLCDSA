#include <stdio.h>
#include <string.h>
#define max_Size 51

int main(int argc, char const *argv[]) {
    // ??
    char A[max_Size], B[max_Size];
    // ??
    scanf("%s %s", A, B);
    // ??
    int sizea, sizeb;
    sizea = strlen(A);
    sizeb = strlen(B);
    // ??
    if (sizea > sizeb) {
        printf("%s\n", A);
    } else {
        printf("%s\n", B);
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s %s", A, B);
     ^