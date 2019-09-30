#include <stdio.h>
#include <string.h>
#define Sizechar 4
// ?????????
void charToDigit (char A[], char B[]) {
    int digit = 0, num[2*Sizechar];
    int lena, lenb;
    lena = strlen(A); lenb = strlen(B);
    // ?????????
    for (size_t i = 0; i < lena; i++) {
        num[i] = A[i] - '0';
    }
    for (size_t i = 0; i < lenb; i++) {
        num[lena+i] = B[i] - '0';
    }
    // ?????
    for (size_t i = 0; i < (lena+lenb); i++) {
        digit = digit*10 + num[i];
    }
    digit = 2*digit;
    printf("%d\n", digit);
}

// ???
int main(int argc, char const *argv[]) {
    // ??
    char A[Sizechar], B[Sizechar];
    // ??
    scanf("%s %s", A, B);
    // ??
    charToDigit(A, B);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:29:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s %s", A, B);
     ^