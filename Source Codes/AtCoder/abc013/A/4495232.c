#include <stdio.h>

int main(int argc, char const *argv[]) {
    // ??
    char X;
    // ??
    scanf("%c", &X);
    // ??
    int ans;
    ans = X-'A'+1;
    // ??
    printf("%d\n", ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%c", &X);
     ^