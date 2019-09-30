#include <stdio.h>

int main(int argc, char const *argv[]) {
    // ??
    char S[5];
    int N;
    // ??
    scanf("%s\n", S);
    scanf("%d", &N);
    N--;
    // ??
    printf("%c%c\n", S[N/5], S[N%5]);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s\n", S);
     ^
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &N);
     ^