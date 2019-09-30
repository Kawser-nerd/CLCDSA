#include <stdio.h>

int main(int argc, char const *argv[]) {
    // ??
    int X;
    // ??
    scanf("%d", &X);
    // ??
    int ans;
    ans = X/10 + X%10;
    // ??
    printf("%d\n", ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &X);
     ^