#include <stdio.h>
#define min(a, b) (a<b ? a:b)
// ???
int main(int argc, char const *argv[]) {
    // ??
    int N, T;
    scanf("%d %d", &N, &T);
    int A[N];
    for (size_t i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
    // ???????
    long ans = 0;
    for (size_t i = 0; i < N-1; i++) {
        ans += min(T, A[i+1]-A[i]);
    }
    ans+=T;
    // ??
    printf("%ld\n", ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d", &N, &T);
     ^
./Main.c:10:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d", &A[i]);
         ^