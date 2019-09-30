#include <stdio.h>

int main(int argc, char const *argv[]) {
    // ??
    int A, B, C, K;
    int child, adult;
    // ??
    scanf("%d %d %d %d", &A, &B, &C, &K);
    scanf("%d %d", &child, &adult);
    // ??
    int cost;
    if (K <= (child+adult)) {
        cost = (A*child+B*adult) - C*(child+adult);
    } else {
        cost = A*child+B*adult;
    }
    // ??
    printf("%d\n", cost);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d %d %d", &A, &B, &C, &K);
     ^
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d", &child, &adult);
     ^