#include <stdio.h>

int main(int argc, char const *argv[]) {
    // ??
    int M, D;
    // ??
    scanf("%d %d", &M, &D);
    // ??
    if (M%D == 0) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    return 0;
} ./Main.c: In function �main�:
./Main.c:7:5: warning: ignoring return value of �scanf�, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d", &M, &D);
     ^