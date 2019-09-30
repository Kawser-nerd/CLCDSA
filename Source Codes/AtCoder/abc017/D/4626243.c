#include <stdio.h>
#define sizeN 111111
// ????
long lPow(int n, int m) {
    if (m == 0) {
        return n;
    } else if (m%2 == 2) {
        return lPow(n, m/2)*lPow(n, m/2);
    } else {
        return n*lPow(n, m-1);
    }
}
// ????????
// dp[i] = ?? [j, i) ???????????????????? j ????? dp[j] ???
void syakutoriDP (int N, int M, int taste[]) {
    // ????????????????????
    int Fvari[M]; // ????????? i ??????
    int range[N+1];   // ? ? i ?????????
    int  left = 0;
    for (int right = 0; right < N; right++) {
        Fvari[taste[right]] ++;
        //printf("Fvari %d\n", Fvari[taste[right]]);
        while (left < right && Fvari[taste[right]] > 1) {
            Fvari[taste[left]] --;
            left ++;
        }
        //printf("left %d right %d\n", left, right);
        range[right+1] = left;
    }
    // ???????
    long dp[sizeN], sum[sizeN];
    long Mod = lPow(10, 8) + 7; // Mod
    dp[0] = 1;
    sum[0] = 0; sum[1] = 1;
    for (int i = 1; i <= N; ++i) {
        dp[i] = (sum[i] - sum[range[i]] + Mod) % Mod; // DP
        sum[i+1] = (sum[i] + dp[i]) % Mod; // ??
    }
    printf("%ld\n", dp[N]);
}

// ???
int main(int argc, char const *argv[]) {
    // N:????? M:???
    int N, M;
    int taste[sizeN];
    // ??
    scanf("%d %d", &N, &M);
    for (size_t i = 0; i < N; i++) {
        scanf("%d", &taste[i]);
        taste[i]--;    // ???
    }
    // ??
    syakutoriDP(N, M, taste);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:48:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d", &N, &M);
     ^
./Main.c:50:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d", &taste[i]);
         ^