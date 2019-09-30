#include <stdio.h>
#define sizeA 100

int main(int argc, char const *argv[]) {
    // ??
    int N, ai, cnt = 0;
    int sum = 0;
    // ??
    scanf("%d", &N);
    for (size_t i = 0; i < N; i++) {
        scanf("%d", &ai);
        if (ai != 0) { cnt++; }
        sum += ai;
    }
    // ????
    int ans = (sum+cnt-1)/cnt;
    printf("%d\n", ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &N);
     ^
./Main.c:11:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d", &ai);
         ^