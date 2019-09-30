#include <stdio.h>

int main(int argc, char const *argv[]) {
    // ??
    int a, b;
    // ??
    scanf("%d %d", &a, &b);
    // ??
    int ans = b-a%b;
    ans = (ans==b ? 0:ans);
    // ??
    printf("%d\n", ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d", &a, &b);
     ^