#include <stdio.h>

int main(int argc, char const *argv[]) {
    // ??
    int N;
    scanf("%d", &N);
    int a[N], memo[N], sum = 0;
    // ??
    for (size_t i = 0; i < N; i++) {
        scanf("%d", &a[i]);
        sum += a[i];
        memo[i] = sum;
    }
    // ???????
    // ????
    if (sum%N != 0) {
        printf("-1\n");
        return 0;
    }
    // ??
    int bridges = 0;
    int people = sum/N;
    for (int i = 0; i < N - 1; ++i){
        int l = memo[i], r = sum - memo[i]; //?????????????????
        if(l == people * (i + 1) && r == people * (N - (i + 1))) { continue;
        }
        bridges++;
    }
    // ??
    printf("%d\n", bridges);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &N);
     ^
./Main.c:10:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d", &a[i]);
         ^