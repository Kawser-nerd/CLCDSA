#include <stdio.h>

int main(int argc, char const *argv[]) {
    // ??
    int N;
    // ??
    scanf("%d", &N );
    // ??
    int ans;
    ans = (N%2==0 ? N/2:N/2+1);
    // ??
    printf("%d\n", ans );
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &N );
     ^