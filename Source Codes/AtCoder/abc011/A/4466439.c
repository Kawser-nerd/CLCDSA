#include <stdio.h>

int main(int argc, char const *argv[]) {
    // ??
    int N, ans;
    // ??
    scanf("%d", &N );
    // ??
    if (N==12) {
        ans =1;
        printf("%d\n", ans );
    } else {
        printf("%d\n", N+1 );
    }
    return 0;
} ./Main.c: In function �main�:
./Main.c:7:5: warning: ignoring return value of �scanf�, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &N );
     ^